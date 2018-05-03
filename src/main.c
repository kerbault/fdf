/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 15:51:29 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 19:26:54 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		kf(int keycode, void *param)
{
	param = NULL;
	// ft_putstr("keycode:");
	// ft_putnbr(keycode);
	// ft_putchar('\n');
	if (keycode == 53)
		exit(0);
	return (0);
}

t_s_map	size_map(int fd)
{
	t_s_map	s_map;
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

int		**map_malloc(t_s_map s_map, t_s_map size)
{
	int		**map;
	int		*map2;

	map = (int **)malloc(s_map.length * s_map.width * sizeof(int) + s_map.length * sizeof(int *));
	map2 = (int *)(map + s_map.length);
	while (size.length < s_map.length)
	{
		map[size.length] = map2;
		size.length++;
		map2 += s_map.width;
	}
	return (map);
}

int		**read_map(int fd, t_s_map s_map)
{
	char	*line;
	char	**map_part;
	int		**map;
	t_s_map	size;

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

t_point	set_point1(int x, int y, t_s_map s_map, int **map)
{
	t_point	p;

	p.x1 = (cos(0.3) * x * 20 - sin(0.3) * y * 20) + 60 * (s_map.length / 8) - map[x][y];
	p.y1 = ((sin(0.3) * x * 25 + cos(0.3) * y * 25) + 60) - map[x][y];
	p.x2 = (cos(0.3) * (x + 1) * 20 - sin(0.3) * y * 20) + 60 * (s_map.length / 8) - map[x + 1][y];
	p.y2 = ((sin(0.3) * (x + 1) * 25 + cos(0.3) * y * 25) + 60) - map[x + 1][y];
	return (p);
}

t_point set_point2(int x, int y, t_s_map s_map, int **map)
{
	t_point	p;

	p.x1 = (cos(0.3) * x * 20 - sin(0.3) * y * 20) + 60 * (s_map.length / 8) - map[x][y];
	p.y1 = ((sin(0.3) * x * 25 + cos(0.3) * y * 25) + 60) - map[x][y];
	p.x2 = (cos(0.3) * x * 20 - sin(0.3) * (y + 1) * 20) + 60 * (s_map.length / 8) - map[x][y + 1];
	p.y2 = ((sin(0.3) * x * 25 + cos(0.3) * (y + 1) * 25) + 60 - (map[x][y + 1]));
	return (p);
}

void	print_map(void *mlx, void *win, int **map, t_s_map s_map)
{
	int		x;
	int		y;
	t_point	p;
	void	*img;

	x = -1;
	y = -1;
	img = mlx_new_image(mlx, s_map.length * 40, s_map.width * 40);
	while (y++ < s_map.width - 1)
	{
		while (x++ < s_map.length - 1)
		{
			if (x != s_map.length - 1)
			{
				p = set_point1(x, y, s_map, map);
				draw_seg(p, mlx, win);
			}
			if (y != s_map.width - 1)
			{
				p = set_point2(x, y, s_map, map);
				draw_seg(p, mlx, win);
			}
		}
		x = -1;
	}
}

int main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int		fd;
	int		**map;
	t_s_map	s_map;

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
	win = mlx_new_window(mlx, s_map.length * 25, s_map.width * 40, av[1]);
	print_map(mlx, win, map, s_map);
	mlx_pixel_put(mlx, win, 1, 1, 0xFFFFFF);
	mlx_key_hook(win, kf, 0);
	free(map);
	mlx_loop(mlx);
	// point.x1 = 0 + 100;
	// point.y1 = 0 + 100;
	// point.x2 = 100 + 100;
	// point.y2 = 20 + 100;
	// mlx_pixel_put(mlx_ptr, win_ptr, 100+100, 20+100, 0xFF0000);
	// draw_seg(point, mlx_ptr, win_ptr); // BB 1

	// point.x1 = 100 + 100;
	// point.y1 = 20 + 100;
	// point.x2 = 200 + 100;
	// point.y2 = 40 + 100;
	// draw_seg(point, mlx_ptr, win_ptr); // BB 2
	// mlx_pixel_put(mlx_ptr, win_ptr, 100+100, 20+100, 0xFF0000);

	// point.x1 = 0 + 100;
	// point.y1 = 0 + 100;
	// point.x2 = 100 + 100;
	// point.y2 = -50 + 100;
	// mlx_pixel_put(mlx_ptr, win_ptr, 100+100, -50+100, 0xFF0000);
	// draw_seg(point, mlx_ptr, win_ptr); // DD 3

	// point.x1 = 0 + 100;
	// point.y1 = 0 + 100;
	// point.x2 = 50 + 100;
	// point.y2 = -100 + 100;
	// mlx_pixel_put(mlx_ptr, win_ptr, 50+100, -100+100, 0xFF0000);
	// draw_seg(point, mlx_ptr, win_ptr); // DD 4

	// point.x1 = 0 + 100;
	// point.y1 = 0 + 100;
	// point.x2 = -50 + 100;
	// point.y2 = -100 + 100;
	// mlx_pixel_put(mlx_ptr, win_ptr, -50+100, -100+100, 0xFF0000);
	// draw_seg(point, mlx_ptr, win_ptr); // HH 5

	// point.x1 = 0 + 100;
	// point.y1 = 0 + 100;
	// point.x2 = -100 + 100;
	// point.y2 = -50 + 100;
	// mlx_pixel_put(mlx_ptr, win_ptr, -100+100, -50+100, 0xFF0000);
	// draw_seg(point, mlx_ptr, win_ptr); // HH 6

	// point.x1 = 0 + 100;
	// point.y1 = 0 + 100;
	// point.x2 = -100 + 100;
	// point.y2 = 50 + 100;
	// mlx_pixel_put(mlx_ptr, win_ptr, -100+100, 50+100, 0xFF0000);
	// draw_seg(point, mlx_ptr, win_ptr); // GG 7

	// point.x1 = 0 + 100;
	// point.y1 = 0 + 100;
	// point.x2 = -50 + 100;
	// point.y2 = 100 + 100;
	// mlx_pixel_put(mlx_ptr, win_ptr, -50+100, 100+100, 0xFF0000);
	// draw_seg(point, mlx_ptr, win_ptr); // GG 8

	// point.x1 = 0+ 100;
	// point.y1 = 0+ 100;
	// point.x2 = 10+ 100;
	// point.y2 = -10+ 100;
	// draw_seg(point, mlx_ptr, win_ptr); // HG 9

	// point.x1 = 0+ 100;
	// point.y1 = 0+ 100;
	// point.x2 = -10+ 100;
	// point.y2 = 10+ 100;
	// draw_seg(point, mlx_ptr, win_ptr); // HG 10

	// point.x1 = 0+ 100;
	// point.y1 = 0+ 100;
	// point.x2 = 90+ 100;
	// point.y2 = 110+ 100;
	// draw_seg(point, mlx_ptr, win_ptr); // BD 11

	// point.x1 = 0+ 100;
	// point.y1 = 0+ 100;
	// point.x2 = 110+ 100;
	// point.y2 = 90+ 100;
	// draw_seg(point, mlx_ptr, win_ptr); // BD 12

	// point.x1 = 0+ 100;
	// point.y1 = 0+ 100;
	// point.x2 = 10+ 100;
	// point.y2 = 90+ 100;
	// draw_seg(point, mlx_ptr, win_ptr); // BG 13

	// point.x1 = 0;
	// point.y1 = 0;
	// point.x2 = -10;
	// point.y2 = 110;
	// draw_seg(point, mlx_ptr, win_ptr); // BG 14

	// point.x1 = 0;
	// point.y1 = 0;
	// point.x2 = 90;
	// point.y2 = 10;
	// draw_seg(point, mlx_ptr, win_ptr); // HD 15

	// point.x1 = 0;
	// point.y1 = 0;
	// point.x2 = 110;
	// point.y2 = -20;
	// draw_seg(point, mlx_ptr, win_ptr); // HD 16
	return (0);
}