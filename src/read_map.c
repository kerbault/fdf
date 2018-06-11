/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_read.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 16:45:36 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 17:53:05 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	size_map(int fd, t_size *gsize)
{
	char	*line;
	char	**length;

	gsize->width = 0;
	gsize->length = 0;
	while (get_next_line(fd, &line))
	{
		gsize->width++;
		length = ft_strsplit(line, ' ');
	}
	while (*length != NULL)
	{
		gsize->length++;
		length++;
	}
	close(fd);
}

int		**map_malloc(t_map size)
{
	int		**map;
	int		*map2;

	map = (int **)malloc(W_X * W_Y * sizeof(int) + \
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
	size.length = 0;
	map = map_malloc(size);
	while (get_next_line(fd, &line))
	{
		map_part = ft_strsplit(line, ' ');
		while (*map_part != NULL)
		{
			map[size.width][size.length] = ft_atoi(*map_part);
			size.width++;
			map_part++;
		}
		free(line);
		size.length++;
		size.width = 0;
	}
	free(line);
	return (map);
}
