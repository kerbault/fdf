/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 15:51:29 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 15:48:26 by kerbault    ###    #+. /#+    ###.fr     */
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

void	opt_def(t_opt *opt, t_size gsize)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	opt->x_rat = 3;
	opt->y_rat = 2;
	opt->z_rat = 0.5;
	opt->x_decal = W_X / 2;
	opt->y_decal = W_Y / 2;
	opt->tilt = 1;
	opt->x_med = gsize.length - 1;
	opt->y_med = gsize.width - 1;
	if (opt->x_med == 0 || opt->y_med == 0)
		ft_close("Invalid Map", -1);
	opt->t_med = opt->tilt / opt->x_rat;
	i = (W_Y - 50) / (opt->y_rat * opt->y_med);
	j = (W_X - 50) / (opt->x_rat * (opt->x_med + (opt->y_med * opt->t_med)));
	if (i > j)
		opt->mult = j;
	else
		opt->mult = i;
	opt->x_mult = opt->x_rat * opt->mult;
	opt->y_mult = opt->y_rat * opt->mult;
	opt->z_mult = opt->z_rat * opt->mult;
}

void	loop(t_main main)
{
	mlx_hook(main.win, 2, 0, kf, 0);
	mlx_loop(main.mlx);
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
	if (main.fd == -1 || open(av[1], O_DIRECTORY) != -1)
		ft_close("usage : ./fdf <map>.fdf", EXIT_FAILURE);
	if (!(s_map = (t_map *)malloc(sizeof(t_map))))
		ft_close("Map allocation failed", EXIT_FAILURE);
	size_map(main.fd, &gsize);
	main.fd = open(av[1], O_RDONLY);
	opt_def(&opt, gsize);
	main.map = read_map(main.fd);
	close(main.fd);
	main.mlx = mlx_init();
	main.win = mlx_new_window(main.mlx, W_X, W_Y, av[1]);
	set_img(main.mlx, s_map);
	set_map(main, s_map, gsize, opt);
	mlx_put_image_to_window(main.mlx, main.win, s_map->ptr, 0, 0);
	free(main.map);
	loop(main);
	return (0);
}
