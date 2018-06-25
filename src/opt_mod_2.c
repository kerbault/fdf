/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opt_mod_2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/21 14:36:18 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/21 22:45:14 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_zero(t_glob *glob)
{
	ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
	opt_def(glob);
	mlx_clear_window(glob->mlx, glob->win);
	glob->col = WHITE;
	set_map(*glob);
	mlx_put_image_to_window(glob->mlx, glob->win, glob->s_map->ptr, 0, 0);
}

void	ft_decrease(t_glob *glob)
{
	ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
	glob->opt.z_mult -= 0.5;
	mlx_clear_window(glob->mlx, glob->win);
	glob->col = WHITE;
	set_map(*glob);
	mlx_put_image_to_window(glob->mlx, glob->win, glob->s_map->ptr, 0, 0);
}

void	ft_increase(t_glob *glob)
{
	ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
	glob->opt.z_mult += 0.5;
	mlx_clear_window(glob->mlx, glob->win);
	glob->col = WHITE;
	set_map(*glob);
	mlx_put_image_to_window(glob->mlx, glob->win, glob->s_map->ptr, 0, 0);
}

void	ft_zoomin(t_glob *glob)
{
	ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
	glob->opt.mult *= 1.1;
	mlx_clear_window(glob->mlx, glob->win);
	glob->col = WHITE;
	set_map(*glob);
	mlx_put_image_to_window(glob->mlx, glob->win, glob->s_map->ptr, 0, 0);
}

void	ft_zoomout(t_glob *glob)
{
	ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
	glob->opt.mult /= 1.1;
	mlx_clear_window(glob->mlx, glob->win);
	glob->col = WHITE;
	set_map(*glob);
	mlx_put_image_to_window(glob->mlx, glob->win, glob->s_map->ptr, 0, 0);
}
