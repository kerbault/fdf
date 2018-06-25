/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_map.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 18:14:22 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 23:58:27 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	fdf_comment(t_glob *glob)
{
	mlx_string_put(glob->mlx, glob->win, 10, 5, WHITE, "< or 4 left");
	mlx_string_put(glob->mlx, glob->win, 10, 20, WHITE, "> or 6 righ");
	mlx_string_put(glob->mlx, glob->win, 10, 35, WHITE, "^ or 8 up");
	mlx_string_put(glob->mlx, glob->win, 10, 50, WHITE, "v or 2 down");
	mlx_string_put(glob->mlx, glob->win, 10, 65, WHITE, "5 center");
	mlx_string_put(glob->mlx, glob->win, 10, 80, WHITE, "+ zoomin");
	mlx_string_put(glob->mlx, glob->win, 10, 95, WHITE, "- zoomout");
	mlx_string_put(glob->mlx, glob->win, 10, 110, WHITE, "0 reset");
	mlx_string_put(glob->mlx, glob->win, 10, 125, WHITE, "1 decrease");
	mlx_string_put(glob->mlx, glob->win, 10, 140, WHITE, "3 increase");
	mlx_string_put(glob->mlx, glob->win, 10, 155, WHITE, "9 color");
}

int		seg_check(t_point pt)
{
	if (pt.x1 == pt.x2 && pt.y1 == pt.y2)
		return (0);
	if (pt.x1 < 0)
		if (pt.x2 < 0)
			return (0);
	if (pt.x2 > W_X)
		if (pt.x1 > W_X)
			return (0);
	if (pt.y1 < 0)
		if (pt.y2 < 0)
			return (0);
	if (pt.y2 > W_Y)
		if (pt.y1 > W_Y)
			return (0);
	return (1);
}

int		set_pixel(t_point pt, t_glob glob)
{
	int	ipixel;

	ipixel = pt.x1 + pt.y1 * W_X;
	if (pt.x1 >= 0 && pt.x1 < W_X && pt.y1 >= 0 && pt.y1 < W_Y)
	{
		glob.s_map->fig[ipixel] = glob.col;
		return (0);
	}
	return (-1);
}

void	set_seg(t_point pt, t_glob glob)
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
		set_pixel(pt, glob);
		if (seg_check(pt) == 0)
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

void	set_map(t_glob glob)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	glob.opt.tmp_tilt = glob.opt.tilt * glob.opt.mult;
	while (y++ < glob.width - 1)
	{
		while (x++ < glob.length - 1)
		{
			if (x < W_X && (x + 1) < glob.length)
				set_seg(pers_cav_ver(x, y, glob.map, glob.opt), glob);
			if (y < W_Y && (y + 1) < glob.width)
				set_seg(pers_cav_hor(x, y, glob.map, glob.opt), glob);
		}
		glob.opt.tilt += glob.opt.tmp_tilt;
		x = -1;
	}
}
