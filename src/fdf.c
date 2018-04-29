/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 14:41:15 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/29 08:02:24 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void draw_seg2(t_point point, void *mlx_ptr, void *win_ptr)
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

void draw_seg3(t_point point, void *mlx_ptr, void *win_ptr)
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

void draw_hd(t_point point, void *mlx_ptr, void *win_ptr)
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

void draw_seg5(t_point point, void *mlx_ptr, void *win_ptr)
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

void draw_seg6(t_point point, void *mlx_ptr, void *win_ptr)
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

void draw_seg7(t_point point, void *mlx_ptr, void *win_ptr)
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

void draw_hg1(t_point point, void *mlx_ptr, void *win_ptr)
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

void draw_hg2(t_point point, void *mlx_ptr, void *win_ptr)
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

int draw_seg(t_point point, void *mlx_ptr, void *win_ptr)
{
	if ((point.dx = point.x2 - point.x1) > 0)
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
		else // DD
			while (point.x1 + 1 != point.x2)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
				point.x1 += 1;
			}
	}
	else if (point.dx < 0)
	{
		if ((point.dy = point.y2 - point.y1) > 0)
		{
			if (-point.dx >= point.dy)
				draw_seg6(point, mlx_ptr, win_ptr);
			else
				draw_seg7(point, mlx_ptr, win_ptr);
		}
		else if (point.dy < 0) // HG
		{
			if (point.dx <= point.dy)
				draw_hg1(point, mlx_ptr, win_ptr);
			else
				draw_hg2(point, mlx_ptr, win_ptr);
		}
		else // GG
			while (point.x1 - 1 != point.x2)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
				point.x1 -= 1;
			}
	}
	else
	{
		if ((point.dy = point.y2 - point.y1) > 0) // BB
			while (point.y1 + 1 != point.y2)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
				point.y1 += 1;
			}
		if (point.dy < 0) // HH
			while (point.y1 - 1 != point.y2)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
				point.y1 -= 1;
			}
	}
	return (0);
}

int deal_key(int key, void *param)
{
	if (key || param)
		ft_putnbr(key);
	ft_putchar('\n');
	return (0);
}

int main(int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;
	int size;
	t_point point;

	if (argc != 2)
	{
		ft_putstr("usage : ./fdf <map>.fdf");
		exit(0);
	}
	size = ft_atoi(argv[1]);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, size, size, "test");

	// point.x1 = 0 + 100;
	// point.y1 = 0 + 100;
	// point.x2 = 50 + 100;
	// point.y2 = 100 + 100;
	// draw_seg(point, mlx_ptr, win_ptr); // BB 1

	// point.x1 = 0 + 100;
	// point.y1 = 0 + 100;
	// point.x2 = 100 + 100;
	// point.y2 = 50 + 100;
	// draw_seg(point, mlx_ptr, win_ptr); // BB 2

	// point.x1 = 0 + 100;
	// point.y1 = 0 + 100;
	// point.x2 = 100 + 100;
	// point.y2 = -50 + 100;
	// draw_seg(point, mlx_ptr, win_ptr); // DD 3

	// point.x1 = 0 + 100;
	// point.y1 = 0 + 100;
	// point.x2 = 50 + 100;
	// point.y2 = -100 + 100;
	// draw_seg(point, mlx_ptr, win_ptr); // DD 4

	// point.x1 = 0 + 100;
	// point.y1 = 0 + 100;
	// point.x2 = -50 + 100;
	// point.y2 = -100 + 100;
	// draw_seg(point, mlx_ptr, win_ptr); // HH 5

	// point.x1 = 0 + 100;
	// point.y1 = 0 + 100;
	// point.x2 = -100 + 100;
	// point.y2 = -50 + 100;
	// draw_seg(point, mlx_ptr, win_ptr); // HH 6

	// point.x1 = 0 + 100;
	// point.y1 = 0 + 100;
	// point.x2 = -100 + 100;
	// point.y2 = 50 + 100;
	// draw_seg(point, mlx_ptr, win_ptr); // GG 7

	// point.x1 = 0 + 100;
	// point.y1 = 0 + 100;
	// point.x2 = -50 + 100;
	// point.y2 = 100 + 100;
	// draw_seg(point, mlx_ptr, win_ptr); // GG 8

	// point.x1 = 0+ 100;
	// point.y1 = 0+ 100;
	// point.x2 = 10+ 100;
	// point.y2 = -10+ 100;
	// draw_seg(point, mlx_ptr, win_ptr); // HG 9

	// point.x1 = 0+ 100;
	// point.y1 = 0+ 100;
	// point.x2 = -10+ 100;
	// point.y2 = 10+ 100;
	// draw_seg(point, mlx_ptr, win_ptr); // HG 10

	// point.x1 = 0+ 100;
	// point.y1 = 0+ 100;
	// point.x2 = 90+ 100;
	// point.y2 = 110+ 100;
	// draw_seg(point, mlx_ptr, win_ptr); // BD 11

	// point.x1 = 0+ 100;
	// point.y1 = 0+ 100;
	// point.x2 = 110+ 100;
	// point.y2 = 90+ 100;
	// draw_seg(point, mlx_ptr, win_ptr); // BD 12

	// point.x1 = 0+ 100;
	// point.y1 = 0+ 100;
	// point.x2 = 10+ 100;
	// point.y2 = 90+ 100;
	// draw_seg(point, mlx_ptr, win_ptr); // BG 13

	// point.x1 = 0;
	// point.y1 = 0;
	// point.x2 = -10;
	// point.y2 = 110;
	// draw_seg(point, mlx_ptr, win_ptr); // BG 14

	// point.x1 = 0;
	// point.y1 = 0;
	// point.x2 = 90;
	// point.y2 = 10;
	// draw_seg(point, mlx_ptr, win_ptr); // HD 15

	// point.x1 = 0;
	// point.y1 = 0;
	// point.x2 = 110;
	// point.y2 = -20;
	// draw_seg(point, mlx_ptr, win_ptr); // HD 16

	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
