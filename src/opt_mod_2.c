/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opt_mod_2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/21 14:36:18 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/27 17:16:56 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_zero(t_glob *glob)
{
	glob->opt.i_zoom = 0;
	ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
	opt_def_1(glob);
	opt_def_2(glob);
	mlx_clear_window(glob->mlx, glob->win);
	ft_show(*glob);
}

void	ft_decrease(t_glob *glob)
{
	if (glob->opt.z_mult > -20)
	{
		ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
		glob->opt.z_mult -= 0.3;
		mlx_clear_window(glob->mlx, glob->win);
		ft_show(*glob);
	}
}

void	ft_increase(t_glob *glob)
{
	if (glob->opt.z_mult < 20)
	{
		ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
		glob->opt.z_mult += 0.3;
		mlx_clear_window(glob->mlx, glob->win);
		ft_show(*glob);
	}
}

void	ft_zoomin(t_glob *glob)
{
	if (glob->opt.i_zoom <= 50)
	{
		ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
		glob->opt.mult *= 1.1;
		mlx_clear_window(glob->mlx, glob->win);
		glob->opt.i_zoom += 1;
		ft_show(*glob);
	}
}

void	ft_zoomout(t_glob *glob)
{
	if (glob->opt.i_zoom >= -50)
	{
		ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
		glob->opt.mult /= 1.1;
		mlx_clear_window(glob->mlx, glob->win);
		glob->opt.i_zoom -= 1;
		ft_show(*glob);
	}
}
