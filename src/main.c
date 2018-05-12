/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 15:51:29 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 23:35:43 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_img(void *mlx, t_map s_map)
{
	if ((s_map.ptr = mlx_new_image(mlx, W_HEIGHT, W_WIDTH)) == NULL)
		ft_close("error : mlx_new_image()", EXIT_FAILURE);
	if ((s_map.fig = (int *)mlx_get_data_addr(s_map.ptr, &s_map.bpp, &s_map.sl,\
	&s_map.endian)) == NULL)
		ft_close("error : mlx_get_data_addr()", EXIT_FAILURE);
}

void	print_map(void *mlx, void *win, int **map, t_map s_map)
{
	int		x;
	int		y;
	size_t	i;

	i = 0;
	x = -1;
	y = -1;
	while (y++ < s_map.width - 1)
	{
		while (x++ < s_map.length - 1)
		{
			if (x != s_map.length - 1)
				drawseg(pers_cav1(x, y, map, i), mlx, win);
			if (y != s_map.width - 1)
				drawseg(pers_cav2(x, y, map, i), mlx, win);
		}
		i += 10;
		x = -1;
	}
}

int		main(int ac, char **av)
{
	t_main	main;
	t_map	s_map;

	if (ac != 2)
		ft_close("usage : ./fdf <map>.fdf", EXIT_FAILURE);
	main.fd = open(av[1], O_RDONLY);
	s_map = size_map(main.fd);
	main.fd = open(av[1], O_RDONLY);
	main.map = read_map(main.fd, s_map);
	close(main.fd);
	main.mlx = mlx_init();
	main.win = mlx_new_window(main.mlx, W_WIDTH, W_HEIGHT, av[1]);
	// print_map(main.mlx, main.win, main.map, s_map);
	set_img(main.mlx, s_map);
	mlx_put_image_to_window(main.mlx, main.win, main.map, 20, 20);
	mlx_hook(main.win, 2, 0, kf, 0);
	mlx_loop(main.mlx);
	return (0);
}
