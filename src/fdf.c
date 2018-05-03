/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 14:41:15 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 18:56:10 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_seg2(t_point point, void *mlx_ptr, void *win_ptr)
{
	int e;

	e = point.dx;
	point.dx *= 2;
	point.dy *= 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
		if ((point.x1 += 1) == point.x2)
			break ;
		if ((e -= point.dy) < 0)
		{
			point.y1 += 1;
			e += point.dx;
		}
	}
}

void	draw_seg3(t_point point, void *mlx_ptr, void *win_ptr)
{
	int e;

	e = point.dy;
	point.dy *= 2;
	point.dx *= 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
		if ((point.y1 += 1) == point.y2)
			break ;
		if ((e -= point.dx) < 0)
		{
			point.x1 += 1;
			e += point.dy;
		}
	}
}

void	draw_hd(t_point point, void *mlx_ptr, void *win_ptr)
{
	int e;

	e = point.dx;
	point.dx *= 2;
	point.dy *= 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
		if ((point.x1 += 1) == point.x2)
			break ;
		if ((e += point.dy) < 0)
		{
			point.y1 -= 1;
			e += point.dx;
		}
	}
}

void	draw_seg5(t_point point, void *mlx_ptr, void *win_ptr)
{
	int e;

	e = point.dy;
	point.dy *= 2;
	point.dx *= 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
		if ((point.y1 -= 1) == point.y2)
			break ;
		if ((e += point.dx) > 0)
		{
			point.x1 += 1;
			e += point.dy;
		}
	}
}

void	draw_seg6(t_point point, void *mlx_ptr, void *win_ptr)
{
	int e;

	e = point.dx;
	point.dx *= 2;
	point.dy *= 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
		if ((point.x1 -= 1) == point.x2)
			break ;
		if ((e += point.dy) >= 0)
		{
			point.y1 += 1;
			e += point.dx;
		}
	}
}

void	draw_seg7(t_point point, void *mlx_ptr, void *win_ptr)
{
	int e;

	e = point.dy;
	point.dy *= 2;
	point.dx *= 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
		if ((point.y1 += 1) == point.y2)
			break ;
		if ((e += point.dx) <= 0)
		{
			point.x1 -= 1;
			e += point.dy;
		}
	}
}

void	draw_hg1(t_point point, void *mlx_ptr, void *win_ptr)
{
	int e;

	e = point.dx;
	point.dx *= 2;
	point.dy *= 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
		if ((point.x1 -= 1) == point.x2)
			break ;
		if ((e -= point.dy) >= 0)
		{
			point.y1 -= 1;
			e += point.dx;
		}
	}
}

void	draw_hg2(t_point point, void *mlx_ptr, void *win_ptr)
{
	int e;

	e = point.dy;
	point.dy *= 2;
	point.dx *= 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
		if ((point.y1 -= 1) == point.y2)
			break ;
		if ((e -= point.dx) >= 0)
		{
			point.x1 -= 1;
			e += point.dy;
		}
	}
}

int		dx_sup(t_point point, void *mlx_ptr, void *win_ptr)
{
	if ((point.dy = point.y2 - point.y1) > 0)
	{
		if (point.dx >= point.dy)
			draw_seg2(point, mlx_ptr, win_ptr);
		else
			draw_seg3(point, mlx_ptr, win_ptr);
	}
	else if (point.dy < 0)
	{
		if (point.dx >= -point.dy)
			draw_hd(point, mlx_ptr, win_ptr);
		else
			draw_seg5(point, mlx_ptr, win_ptr);
	}
	else
		while (point.x1 + 1 != point.x2)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
			point.x1 += 1;
		}
	return (0);
}

int		dx_inf(t_point point, void *mlx_ptr, void *win_ptr)
{
	if ((point.dy = point.y2 - point.y1) > 0)
	{
		if (-point.dx >= point.dy)
			draw_seg6(point, mlx_ptr, win_ptr);
		else
			draw_seg7(point, mlx_ptr, win_ptr);
	}
	else if (point.dy < 0)
	{
		if (point.dx <= point.dy)
			draw_hg1(point, mlx_ptr, win_ptr);
		else
			draw_hg2(point, mlx_ptr, win_ptr);
	}
	else
		while (point.x1 - 1 != point.x2)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
			point.x1 -= 1;
		}
	return (0);
}

int		draw_seg(t_point point, void *mlx_ptr, void *win_ptr)
{
	if ((point.dx = point.x2 - point.x1) > 0)
	{
		dx_sup(point, mlx_ptr, win_ptr);
	}
	else if (point.dx < 0)
	{
		dx_inf(point, mlx_ptr, win_ptr);
	}
	else
	{
		if ((point.dy = point.y2 - point.y1) > 0)
			while (point.y1 + 1 != point.y2)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
				point.y1 += 1;
			}
		if (point.dy < 0)
			while (point.y1 - 1 != point.y2)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
				point.y1 -= 1;
			}
	}
	return (0);
}
