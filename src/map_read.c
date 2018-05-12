/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_read.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 16:45:36 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 23:32:32 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_map	size_map(int fd)
{
	t_map	s_map;
	char	*line;
	char	**length;

	ft_bzero(&s_map, sizeof(s_map));
	while (get_next_line(fd, &line))
	{
		s_map.width++;
		length = ft_strsplit(line, ' ');
	}
	while (*length != NULL)
	{
		s_map.length++;
		length++;
	}
	close(fd);
	return (s_map);
}

int		**map_malloc(t_map s_map, t_map size)
{
	int		**map;
	int		*map2;

	map = (int **)malloc(s_map.length * s_map.width * sizeof(int) + \
	s_map.length * sizeof(int *));
	map2 = (int *)(map + s_map.length);
	while (size.length < s_map.length)
	{
		map[size.length] = map2;
		size.length++;
		map2 += s_map.width;
	}
	return (map);
}

int		**read_map(int fd, t_map s_map)
{
	char	*line;
	char	**map_part;
	int		**map;
	t_map	size;

	ft_bzero(&size, sizeof(size));
	size.length = 0;
	map = map_malloc(s_map, size);
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
	return (map);
}
