/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 15:51:29 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/27 17:21:06 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_img(void *mlx, t_map *s_map)
{
	if ((s_map->ptr = mlx_new_image(mlx, W_X, W_Y)) == NULL)
		ft_close("error : mlx_new_image()", EXIT_FAILURE);
	if ((s_map->fig = (int *)mlx_get_data_addr(s_map->ptr, &s_map->bpp, \
		&s_map->sl, &s_map->endian)) == NULL)
		ft_close("error : mlx_get_data_addr()", EXIT_FAILURE);
}

void	ft_close(char *msg, int status)
{
	ft_putendl(msg);
	exit(status);
}

void	ft_show(t_glob glob)
{
	set_map(glob);
	mlx_put_image_to_window(glob.mlx, glob.win, glob.s_map->ptr, 0, 0);
	fdf_comment(&glob);
}

void	loop(t_glob *glob)
{
	mlx_hook(glob->win, 17, (1L << 17), red_cross, (t_glob*)glob);
	mlx_hook(glob->win, 2, 0, kf, (t_glob*)glob);
	mlx_loop(glob->mlx);
}

int		main(int ac, char **av)
{
	t_glob	glob;

	if (ac != 2)
		ft_close("usage : ./fdf <map>.fdf", EXIT_FAILURE);
	opt_def_1(&glob);
	glob.fd = open(av[1], O_RDONLY);
	if (glob.fd == -1 || open(av[1], O_DIRECTORY) != -1)
		ft_close("usage : ./fdf <map>.fdf", EXIT_FAILURE);
	ft_putendl("Testing map.");
	if (!(glob.s_map = (t_map *)malloc(sizeof(t_map))))
		ft_close("Map allocation failed", EXIT_FAILURE);
	size_map(&glob);
	glob.fd = open(av[1], O_RDONLY);
	opt_def_2(&glob);
	glob.map = read_map(glob.fd);
	close(glob.fd);
	if ((glob.mlx = mlx_init()) == NULL)
		ft_close("mlx_init failed.", EXIT_FAILURE);
	if ((glob.win = mlx_new_window(glob.mlx, W_X, W_Y, av[1])) == NULL)
		ft_close("mlx_new_window failed.", EXIT_FAILURE);
	set_img(glob.mlx, glob.s_map);
	ft_show(glob);
	loop(&glob);
	return (0);
}
