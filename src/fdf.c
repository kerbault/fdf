/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 14:41:15 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/29 05:35:54 by kerbault    ###    #+. /#+    ###.fr     */
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
			break;
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
			break;
		if ((e -= point.dy) < 0)
		{
			point.x1 += 1;
			e += point.dy;
		}
	}
}

void draw_seg4(t_point point, void *mlx_ptr, void *win_ptr)
{
	int e;

	e = point.dy;
	point.dx *= 2;
	point.dy *= 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
		if ((point.x1 += 1) == point.x2)
			break;
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
			break;
		if ((e += point.dx) > 0)
		{
			point.x1 += 1;
			e += point.dy;
		}
	}
}

void draw_seg6(t_point point, void *mlx_ptr, void *win_ptr)
{
	int	e;

	e = point.dx;
	point.dx *= 2;
	point.dy *= 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
		if ((point.x1 -= 1) == point.x2)
			break;
		if ((e += point.dy) >= 0)
		{
			point.y1 += 1;
			e += point.dx;
		}
	}
}

void draw_seg7(t_point point, void *mlx_ptr, void *win_ptr)
{
	int	e;

	e = point.dy;
	point.dy *= 2;
	point.dx *= 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
		if ((point.y1 += 1) == point.y2)
			break;
		if ((e += point.dx) <= 0)
		{
			point.x1 += 1;
			e += point.dy;
		}
	}
}

void draw_seg8(t_point point, void *mlx_ptr, void *win_ptr)
{
	int	e;

	e = point.dx;
	point.dx *= 2;
	point.dy *= 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
		if ((point.x1 -= 1) == point.x2)
			break;
		if ((e -= point.dy) >= 0)
		{
			point.y1 -= 1;
			e += point.dx;
		}
	}
}

void draw_seg9(t_point point, void *mlx_ptr, void *win_ptr)
{
	int	e;

	e = point.dy;
	point.dy *= 2;
	point.dx *= 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
		if ((point.y1 -= 1) == point.y2)
			break;
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
				draw_seg4(point, mlx_ptr, win_ptr);
			else
				draw_seg5(point, mlx_ptr, win_ptr);
		}
		else
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
		else if (point.dy < 0)
		{
			if (point.dx <= point.dy)
				draw_seg8(point, mlx_ptr, win_ptr);
			else
				draw_seg9(point, mlx_ptr, win_ptr);
		}
		else
			while (point.x1 - 1 != point.x2)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
				point.x1 -= 1;
			}
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
	point.x1 = 50;
	point.y1 = 50;
	point.x2 = 50;
	point.y2 = 100;
	draw_seg(point, mlx_ptr, win_ptr); // OK

	point.x1 = 50;
	point.y1 = 50;
	point.x2 = 100;
	point.y2 = 50;
	draw_seg(point, mlx_ptr, win_ptr); // OK

	point.x1 = 50;
	point.y1 = 50;
	point.x2 = 50;
	point.y2 = 0;
	draw_seg(point, mlx_ptr, win_ptr); // OK

	point.x1 = 50;
	point.y1 = 50;
	point.x2 = 0;
	point.y2 = 50;
	draw_seg(point, mlx_ptr, win_ptr); // OK

	point.x1 = 50;
	point.y1 = 50;
	point.x2 = 0;
	point.y2 = 0;
	draw_seg(point, mlx_ptr, win_ptr); // ok

	point.x1 = 50;
	point.y1 = 50;
	point.x2 = 100;
	point.y2 = 100;
	draw_seg(point, mlx_ptr, win_ptr); // ok

	point.x1 = 50;
	point.y1 = 50;
	point.x2 = 0;
	point.y2 = 100;
	draw_seg(point, mlx_ptr, win_ptr); // ok

	point.x1 = 50;
	point.y1 = 50;
	point.x2 = 100;
	point.y2 = 0;
	draw_seg(point, mlx_ptr, win_ptr); // COMPLETEMENT PAS OK

	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
