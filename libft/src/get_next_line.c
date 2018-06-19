/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 16:36:06 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/18 15:52:16 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
** ft_strchr pour trouver un char /n dans ma chaine
** ft_strdup pour dupliquer la string
** ft_strjoin pour additionner les deux chaines
** ft_bzero
*/

static t_gnl	*ft_fdcheck(t_gnl **lst_fd, int fd)
{
	t_gnl	*new;
	t_gnl	*tmp;

	tmp = *lst_fd;
	if (tmp != NULL)
	{
		while (tmp->next && tmp->fd != fd)
			tmp = tmp->next;
		if (tmp->fd == fd)
			return (tmp);
	}
	MALLOC_CHECK2((new = (t_gnl *)malloc(sizeof(t_gnl))));
	new->fd = fd;
	new->str = ft_strnew(0);
	new->size = 0;
	new->nb = 0;
	new->next = NULL;
	if (tmp == NULL)
		*lst_fd = new;
	else
		tmp->next = new;
	return (new);
}

static int		*ft_mkline(t_gnl *lst, char **line)
{
	char	*tmp;

	if (lst->endl != NULL)
	{
		lst->endl[0] = '\0';
		*line = ft_strdup(lst->str);
		lst->endl++;
		tmp = ft_strdup(lst->endl);
		free(lst->str);
		lst->str = tmp;
		lst->size = ft_strlen(lst->str);
	}
	else
	{
		*line = ft_strdup(lst->str);
		tmp = ft_strnew(0);
		free(lst->str);
		lst->str = tmp;
		lst->size = ft_strlen(lst->str);
		lst->endl = NULL;
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	char			*str;
	t_gnl			*tmp;
	static t_gnl	*mult_fd = NULL;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (-1);
	NULL_CHECK1((tmp = ft_fdcheck(&mult_fd, fd)));
	while ((tmp->endl = ft_strchr(tmp->str, '\n')) == NULL
	&& (tmp->nb = read(tmp->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[tmp->nb] = '\0';
		MALLOC_CHECK1((str = ft_strjoin(tmp->str, buff)));
		free(tmp->str);
		tmp->str = str;
		tmp->size += tmp->nb;
		ft_memset(buff, 0, BUFF_SIZE + 1);
	}
	ft_mkline(tmp, line);
	if (ft_strlen(*line) == 0 && tmp->size == 0 && tmp->nb == 0)
		return (0);
	return (1);
}
