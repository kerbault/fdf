/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 15:51:29 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 22:45:34 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_img(void *mlx, t_map s_map)
{
	if ((s_map.ptr = mlx_new_image(mlx, W_WIDTH, W_HEIGHT)) == NULL)
		ft_close("error : mlx_new_image()", EXIT_FAILURE);
	if ((s_map.fig = (int *)mlx_get_data_addr(s_map.ptr, &s_map.bpp, &s_map.sl,
	&s_map.endian)) == NULL)
		ft_close("error : mlx_get_data_addr()", EXIT_FAILURE);
}

void	set_map(t_main main, t_map s_map)
{
	int		x;
	int		y;
	size_t	i;

	i = 0;
	x = -1;
	y = -1;
	while (y++ < W_HEIGHT - 1)
	{
		while (x++ < W_WIDTH - 1)
		{
			if (x != W_WIDTH - 1)
				drawseg(pers_cav1(x, y, main.map, i), s_map);
			if (y != W_HEIGHT - 1)
				drawseg(pers_cav2(x, y, main.map, i), s_map);
		}
		i += 10;
		x = -1;
	}
}

int		main(int ac, char **av)
{
	t_main	main;
	t_map	*s_map;

	if (ac != 2)
		ft_close("usage : ./fdf <map>.fdf", EXIT_FAILURE);
	main.fd = open(av[1], O_RDONLY);
	ft_bzero(&s_map, sizeof(s_map));
	main.map = read_map(main.fd);
	close(main.fd);
	main.mlx = mlx_init();
	main.win = mlx_new_window(main.mlx, W_WIDTH, W_HEIGHT, av[1]);
	s_map = (t_map *)malloc(sizeof(t_map)); // ORIGINAL SEG
	dprintf(1, "%p\n", s_map->fig);
	set_img(main.mlx, *s_map);
	set_map(main, *s_map);
	dprintf(1, "2\n");
	mlx_put_image_to_window(main.mlx, main.win, s_map->ptr, 0, 0);
	mlx_hook(main.win, 2, 0, kf, 0);
	mlx_loop(main.mlx);
	return (0);
}

// int		main(int ac, char **av)
// {
// 	t_main	main;
// 	t_map	s_map;
// 	int		ipixel;

// 	if (ac != 2)
// 		ft_close("usage : ./fdf <map>.fdf", EXIT_FAILURE);
// 	main.fd = open(av[1], O_RDONLY);
// 	ft_bzero(&s_map, sizeof(s_map));
// 	main.mlx = mlx_init();
// 	main.win = mlx_new_window(main.mlx, W_WIDTH, W_HEIGHT, av[1]);
// 	if ((s_map.ptr = mlx_new_image(main.mlx, W_WIDTH, W_HEIGHT)) == NULL)
// 		ft_close("error : mlx_new_image()", EXIT_FAILURE);
// 	if ((s_map.fig = (int *)mlx_get_data_addr(s_map.ptr, &s_map.bpp, &s_map.sl,
// 	&s_map.endian)) == NULL)
// 		ft_close("error : mlx_get_data_addr()", EXIT_FAILURE);
// 	ipixel = 1000 + 1000 * W_WIDTH;
// 	s_map.fig[ipixel] = WHITE;
// 	mlx_put_image_to_window(main.mlx, main.win, s_map.ptr, 0, 0);
// 	mlx_hook(main.win, 2, 0, kf, 0);
// 	mlx_loop(main.mlx);
// 	return (0);
// }
