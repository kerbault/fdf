/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   drawseg.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 18:14:22 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 22:45:35 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		put_pixel(t_point pt, t_map s_map)
{
	int	ipixel;

	ipixel = pt.x1 + pt.y1 * W_HEIGHT;
	pt.col = 0xFFFFFF;
	if (pt.x1 > 0 && pt.x1 < W_WIDTH && pt.y1 > 0 && pt.y1 < W_HEIGHT)
	{
		dprintf(1, "%p\n", s_map.fig);
		s_map.fig[ipixel] = pt.col; //segfault
		dprintf(1, "LA BAS\n");
		return (0);
	}
	return (-1);
}

void	drawseg(t_point pt, t_map s_map)
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
		put_pixel(pt, s_map);
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
