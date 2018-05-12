/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   drawseg.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 18:14:22 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 18:54:39 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	drawseg(t_point pt, void *mlx_ptr, void *win_ptr)
{
	int err;
	int	e2;

	pt.dx = abs(pt.x2 - pt.x1);
	pt.sx = pt.x1 < pt.x2 ? 1 : -1;
	pt.dy = abs(pt.y2 - pt.y1);
	pt.sy = pt.y1 < pt.y2 ? 1 : -1;
	err = (pt.dx > pt.dy ? pt.dx : -pt.dy) / 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, pt.x1, pt.y1, 0xFFFFFF);
		if (pt.x1 == pt.x2 && pt.y1 == pt.y2)
			break ;
		e2 = err;
		if (e2 > -pt.dx)
		{
			err -= pt.dy;
			pt.x1 += pt.sx;
		}
		if (e2 < pt.dy)
		{
			err += pt.dx;
			pt.y1 += pt.sy;
		}
	}
}
