/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 15:51:29 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 16:48:29 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
