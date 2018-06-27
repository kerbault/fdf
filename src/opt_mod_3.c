/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opt_mod_3.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/25 21:52:03 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/27 17:17:11 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_color(t_glob *glob)
{
	if (glob->col == RED)
	{
		ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
		glob->col = BLEU;
		mlx_clear_window(glob->mlx, glob->win);
		ft_show(*glob);
	}
	else if (glob->col == BLEU)
	{
		ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
		glob->col = GREEN;
		mlx_clear_window(glob->mlx, glob->win);
		ft_show(*glob);
	}
	else if (glob->col == GREEN)
	{
		ft_bzero(glob->s_map->fig, (W_X * W_Y * 4));
		glob->col = RED;
		mlx_clear_window(glob->mlx, glob->win);
		ft_show(*glob);
	}
}
