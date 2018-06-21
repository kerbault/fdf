/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 15:51:29 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/21 17:35:46 by kerbault    ###    #+. /#+    ###.fr     */
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

void	opt_def(t_glob *glob)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	glob->opt.x_rat = 3;
	glob->opt.y_rat = 2;
	glob->opt.z_rat = 0.5;
	glob->opt.x_decal = W_X / 2;
	glob->opt.y_decal = W_Y / 2;
	glob->opt.x_med = glob->length - 1;
	glob->opt.y_med = glob->width - 1;
	if (glob->opt.x_med == 0 || glob->opt.y_med == 0)
		ft_close("Invalid Map", -1);
	glob->opt.t_med = glob->opt.tilt / glob->opt.x_rat;
	i = (W_Y - 50) / (glob->opt.y_rat * glob->opt.y_med);
	j = (W_X - 50) / (glob->opt.x_rat * (glob->opt.x_med + \
	(glob->opt.y_med * glob->opt.t_med)));
	if (i > j)
		glob->opt.mult = j;
	else
		glob->opt.mult = i;
	glob->opt.x_mult = glob->opt.x_rat * glob->opt.mult;
	glob->opt.y_mult = glob->opt.y_rat * glob->opt.mult;
	glob->opt.z_mult = glob->opt.z_rat * glob->opt.mult;
}

void	loop(t_glob glob)
{
	mlx_hook(glob.win, 2, 0, kf, 0);
	mlx_loop(glob.mlx);
}

int		main(int ac, char **av)
{
	t_glob	glob;

	glob.opt.tilt = 1;
	if (ac != 2)
		ft_close("usage : ./fdf <map>.fdf", EXIT_FAILURE);
	glob.fd = open(av[1], O_RDONLY);
	if (glob.fd == -1 || open(av[1], O_DIRECTORY) != -1)
		ft_close("usage : ./fdf <map>.fdf", EXIT_FAILURE);
	if (!(glob.s_map = (t_map *)malloc(sizeof(t_map))))
		ft_close("Map allocation failed", EXIT_FAILURE);
	size_map(&glob);
	glob.fd = open(av[1], O_RDONLY);
	opt_def(&glob);
	glob.map = read_map(glob.fd);
	close(glob.fd);
	glob.mlx = mlx_init();
	glob.win = mlx_new_window(glob.mlx, W_X, W_Y, av[1]);
	set_img(glob.mlx, glob.s_map);
	set_map(glob, glob.s_map);
	mlx_put_image_to_window(glob.mlx, glob.win, glob.s_map->ptr, 0, 0);
	free(glob.map);
	loop(glob);
	return (0);
}
