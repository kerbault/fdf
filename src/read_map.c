/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 16:45:36 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 21:46:04 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	size_map(int fd, t_size *gsize)
{
	char	*line;
	size_t	tmp1;
	size_t	tmp2;
	int		bol;

	bol = 0;
	gsize->width = 0;
	gsize->length = 0;
	while (get_next_line(fd, &line) == 1)
	{
		gsize->width++;
		tmp1 = ft_countwd(line);
		free(line);
		if (bol == 0)
		{
			tmp2 = tmp1;
			bol = 1;
		}
		if (tmp1 < tmp2)
			tmp2 = tmp1;
	}
	gsize->length = tmp2;
	close(fd);
	free(line);
}

int		**map_malloc(t_map size)
{
	int	**map;
	int	*map2;

	map = (int **)malloc(W_X * W_Y * sizeof(int) +
						W_X * sizeof(int *));
	map2 = (int *)(map + W_X);
	while (size.length < W_X)
	{
		map[size.length] = map2;
		size.length++;
		map2 += W_Y;
	}
	return (map);
}

int		**read_map(int fd)
{
	char	*line;
	char	**map_part;
	int		**map;
	t_map	size;

	ft_bzero(&size, sizeof(size));
	map = map_malloc(size);
	while (get_next_line(fd, &line) == 1)
	{
		map_part = ft_strsplit(line, ' ');
		free(line);
		if (!ft_isdigit(map_part[0][0]) && map_part[0][0] != '-')
			exit(0);
		while (map_part[size.width] != NULL)
		{
			map[size.width++][size.length] = ft_atoi(map_part[size.width]);
			free(map_part[size.width - 1]);
		}
		free(map_part[size.width]);
		free(map_part);
		size.length++;
		size.width = 0;
	}
	free(line);
	return (map);
}
