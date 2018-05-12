/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 15:51:29 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 16:40:54 by kerbault    ###    #+. /#+    ###.fr     */
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

void	print_map(void *mlx, void *win, int **map, t_map s_map)
{
	int		x;
	int		y;
	void	*img;
	size_t	i;

	i = 0;
	x = -1;
	y = -1;
	img = mlx_new_image(mlx, s_map.length * 40, s_map.width * 40);
	while (y++ < s_map.width - 1)
	{
		while (x++ < s_map.length - 1)
		{
			if (x != s_map.length - 1)
				draw_seg(set_cav1(x, y, map, i), mlx, win);
			if (y != s_map.width - 1)
				draw_seg(set_cav2(x, y, map, i), mlx, win);
		}
		i += 10;
		x = -1;
	}
}

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int		fd;
	int		**map;
	t_map	s_map;

	if (ac != 2)
	{
		ft_putstr("usage : ./fdf <map>.fdf");
		exit(0);
	}
	fd = open(av[1], O_RDONLY);
	s_map = size_map(fd);
	fd = open(av[1], O_RDONLY);
	map = read_map(fd, s_map);
	close(fd);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1200, av[1]);
	print_map(mlx, win, map, s_map);
	mlx_key_hook(win, kf, 0);
	mlx_loop(mlx);
	return (0);
}
