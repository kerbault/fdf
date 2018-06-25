/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opt_mod_1.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/21 14:35:40 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 22:55:32 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_center(t_glob *glob)
{
	ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
	glob->opt.x_decal = W_X / 2;
	glob->opt.y_decal = W_Y / 2;
	mlx_clear_window(glob->mlx, glob->win);
	set_map(*glob);
	mlx_put_image_to_window(glob->mlx, glob->win, glob->s_map->ptr, 0, 0);
	fdf_comment(glob);
}

void	ft_up(t_glob *glob)
{
	ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
	glob->opt.y_decal -= 5;
	mlx_clear_window(glob->mlx, glob->win);
	set_map(*glob);
	mlx_put_image_to_window(glob->mlx, glob->win, glob->s_map->ptr, 0, 0);
	fdf_comment(glob);
}

void	ft_down(t_glob *glob)
{
	ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
	glob->opt.y_decal += 5;
	mlx_clear_window(glob->mlx, glob->win);
	set_map(*glob);
	mlx_put_image_to_window(glob->mlx, glob->win, glob->s_map->ptr, 0, 0);
	fdf_comment(glob);
}

void	ft_left(t_glob *glob)
{
	ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
	glob->opt.x_decal -= 5;
	mlx_clear_window(glob->mlx, glob->win);
	set_map(*glob);
	mlx_put_image_to_window(glob->mlx, glob->win, glob->s_map->ptr, 0, 0);
	fdf_comment(glob);
}

void	ft_right(t_glob *glob)
{
	ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
	glob->opt.x_decal += 5;
	mlx_clear_window(glob->mlx, glob->win);
	set_map(*glob);
	mlx_put_image_to_window(glob->mlx, glob->win, glob->s_map->ptr, 0, 0);
	fdf_comment(glob);
}
