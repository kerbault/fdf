/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:44:34 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 21:49:19 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	ft_countwds(char const *s, char c)
{
	size_t		nb;
	size_t		i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			nb++;
		if (s[i] != c && (i > 0 && s[i - 1] == c))
			nb++;
		i++;
	}
	return (nb);
}

static char		*ft_runstr(char **ptr, char c, int i)
{
	char		*wd;

	wd = NULL;
	while (**ptr)
	{
		if (i == 0 && **ptr != c)
		{
			wd = *ptr;
			break ;
		}
		if (**ptr != c && *(*ptr - 1) == c && i - 1 >= 0)
		{
			wd = *ptr;
			break ;
		}
		*ptr += 1;
		i++;
	}
	if (*(*ptr + 1) != '\0')
		*ptr += 1;
	return (wd);
}

static char		*ft_fillwd(char *wd, size_t size)
{
	char		*tmp;

	tmp = ft_strdup(wd);
	wd = ft_strnew(size);
	wd = ft_strncpy(wd, tmp, size);
	free(tmp);
	tmp = NULL;
	return (wd);
}

static size_t	ft_cutwd(char *wd, char c)
{
	size_t		size;

	size = 0;
	while (wd[size] != '\0' && wd[size] != c)
		size++;
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	char		*str;
	size_t		nb;
	size_t		i;
	size_t		size;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	nb = ft_countwds(s, c);
	MALLOC_CHECK((tab = (char **)malloc(sizeof(*tab) * (nb + 1))));
	while (i < nb)
	{
		tab[i] = ft_runstr(&str, c, i);
		size = ft_cutwd(tab[i], c);
		tab[i] = ft_fillwd(tab[i], size);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
