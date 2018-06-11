/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_map.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 18:14:22 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/11 17:50:13 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		set_pixel(t_point pt, t_map *s_map)
{
	int	ipixel;

	ipixel = pt.x1 + pt.y1 * W_X;
	pt.col = 0xFFFFFF;
	if (pt.x1 >= 0 && pt.x1 < W_X && pt.y1 >= 0 && pt.y1 < W_Y)
	{
		s_map->fig[ipixel] = pt.col;
		return (0);
	}
	return (-1);
}

void	set_seg(t_point pt, t_map *s_map)
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
		set_pixel(pt, s_map);
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

void	set_map(t_main main, t_map *s_map, t_size gsize, t_opt opt)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	opt.tmp_tilt = opt.tilt * opt.mult;
	while (y++ < gsize.width - 1)
	{
		while (x++ < gsize.length - 1)
		{
			if (x < W_X && (x + 1) < gsize.length)
				set_seg(pers_cav1(x, y, main.map, opt), s_map);
			if (y < W_Y && (y + 1) < gsize.width)
				set_seg(pers_cav2(x, y, main.map, opt), s_map);
		}
		opt.tilt += opt.tmp_tilt;
		x = -1;
	}
}
