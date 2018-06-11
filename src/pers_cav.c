/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pers_cav.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 15:40:37 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/11 23:06:23 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	pers_cav1(int x, int y, int **map, t_opt opt)
{
	t_point	pt;

	pt.x1 = (x * opt.x_rat * opt.mult) - opt.tilt + opt.x_decal - opt.x_med;
	pt.y1 = (y * opt.y_rat * opt.mult) - ((map[x][y]) * opt.mult\
	* opt.z_rat) + opt.y_decal - opt.y_med;
	pt.x2 = ((x + 1) * opt.x_rat * opt.mult) - opt.tilt \
	+ opt.x_decal - opt.x_med;
	pt.y2 = (y * opt.y_rat * opt.mult) - (map[x + 1][y] * opt.mult\
	* opt.z_rat) + opt.y_decal - opt.y_med;
	return (pt);
}

t_point	pers_cav2(int x, int y, int **map, t_opt opt)
{
	t_point	pt;

	pt.x1 = (x * opt.x_rat * opt.mult) - opt.tilt + opt.x_decal - opt.x_med;
	pt.y1 = (y * opt.y_rat * opt.mult) - ((map[x][y]) * opt.mult\
	* opt.z_rat) + opt.y_decal - opt.y_med;
	pt.x2 = (x * opt.x_rat * opt.mult) - opt.tilt - opt.tmp_tilt\
	+ opt.x_decal - opt.x_med;
	pt.y2 = ((y + 1) * opt.y_rat * opt.mult) - (map[x][y + 1] * opt.mult\
	* opt.z_rat) + opt.y_decal - opt.y_med;
	return (pt);
}
