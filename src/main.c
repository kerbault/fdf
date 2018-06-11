/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 15:51:29 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/11 21:01:47 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
**	typedef struct	s_opt
** {
** 	int		x_rat;
** 	int		y_rat;
** 	int		z_rat;
** 	int		x_decal;
** 	int		y_decal;
** 	int		x_tilt;
** 	int		y_tilt;
** 	int		mult;
** }				t_opt;
*/

void	set_img(void *mlx, t_map *s_map)
{
	if ((s_map->ptr = mlx_new_image(mlx, W_X, W_Y)) == NULL)
		ft_close("error : mlx_new_image()", EXIT_FAILURE);
	if ((s_map->fig = (int *)mlx_get_data_addr(s_map->ptr, &s_map->bpp, \
		&s_map->sl,
	&s_map->endian)) == NULL)
		ft_close("error : mlx_get_data_addr()", EXIT_FAILURE);
}

void	opt_def(t_opt *opt)
{
	opt->x_rat = 3;
	opt->y_rat = 2;
	opt->z_rat = 1;
	opt->x_decal = 100;
	opt->y_decal = 100;
	opt->tilt = 1;
	opt->mult = 4;
	opt->z_opt = 1;
}

int		main(int ac, char **av)
{
	t_main	main;
	t_map	*s_map;
	t_size	gsize;
	t_opt	opt;

	if (ac != 2)
		ft_close("usage : ./fdf <map>.fdf", EXIT_FAILURE);
	main.fd = open(av[1], O_RDONLY);
	s_map = (t_map *)malloc(sizeof(t_map));
	size_map(main.fd, &gsize);
	main.fd = open(av[1], O_RDONLY);
	main.map = read_map(main.fd);
	close(main.fd);
	opt_def(&opt);
	main.mlx = mlx_init();
	main.win = mlx_new_window(main.mlx, W_X, W_Y, av[1]);
	set_img(main.mlx, s_map);
	set_map(main, s_map, gsize, opt);
	mlx_put_image_to_window(main.mlx, main.win, s_map->ptr, 0, 0);
	mlx_hook(main.win, 2, 0, kf, 0);
	mlx_loop(main.mlx);
	return (0);
}
