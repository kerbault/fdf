/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opt_def.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/27 17:09:18 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/27 17:23:32 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	opt_def_2(t_glob *glob)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	glob->opt.x_rat = 3;
	glob->opt.y_rat = 2;
	glob->opt.z_rat = 0.3;
	glob->opt.x_decal = W_X / 2;
	glob->opt.y_decal = W_Y / 2;
	glob->opt.x_med = glob->length - 1;
	glob->opt.y_med = glob->width - 1;
	if (glob->opt.x_med == 0 || glob->opt.y_med == 0)
		ft_close("Invalid Map", EXIT_FAILURE);
	glob->opt.t_med = glob->opt.tilt / glob->opt.x_rat;
	i = (W_Y - 50) / (glob->opt.y_rat * glob->opt.y_med);
	j = (W_X - 50) / (glob->opt.x_rat * (glob->opt.x_med + \
	(glob->opt.y_med * glob->opt.t_med)));
	if (i > j)
		glob->opt.mult = j;
	else
		glob->opt.mult = i;
	glob->opt.x_mult = glob->opt.x_rat;
	glob->opt.y_mult = glob->opt.y_rat;
	glob->opt.z_mult = glob->opt.z_rat;
}

void	opt_def_1(t_glob *glob)
{
	glob->opt.tilt = 1;
	glob->col = GREEN;
	glob->opt.i_zoom = 0;
}
