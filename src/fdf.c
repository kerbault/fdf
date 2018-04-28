/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 14:41:15 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 18:02:57 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		draw_seg2(t_point point, void *mlx_ptr, void *win_ptr)
{
	int		e;

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

int		draw_seg(t_point point, void *mlx_ptr, void *win_ptr)
{
	int		e;

	if ((point.dx = point.x2 - point.x1) != 0)
	{
		if (point.dx > 0)
		{
			if ((point.dy = point.y2 - point.y1) != 0)
			{
				if (point.dy > 0)
				{
					if (point.dx >= point.dy)
						draw_seg2(point, mlx_ptr, win_ptr);
					else
					{
						e = point.dy;
						point.dy *= 2;
						point.dx *= 2;
						while (1)
						{
							mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
							if ((point.y1 += 1) == point.y2)
								break ;
							if ((e -= point.dy) < 0)
							{
								point.x1 += 1;
								e += point.dy;
							}
						}
					}
				}
				else if (point.dy < 0)
				{
					if (point.dx >= -point.dy)
					{
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
					else
					{
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
				}
				else
					while (point.x1 + 1 != point.x2)
					{
						mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
						point.x1 += 1;
					}
			}
		}
		else if (point.dx < 0)
		{
			if ((point.dy = point.y2 - point.y1) != 0)
			{
				if (point.dy > 0)
				{
					if (-point.dx >= point.dy)
					{
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
					else
					{
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
								point.x1 += 1;
								e += point.dy;
							}
						}
					}
				}
				else if (point.dy < 0)
				{
					if (point.dx <= point.dy)
					{
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
					else
					{
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
				}
				else
					while (point.x1 - 1 != point.x2)
					{
						mlx_pixel_put(mlx_ptr, win_ptr, point.x1, point.y1, 0xFFFFFF);
						point.x1 -= 1;
					}
			}
		}
		else
		{
			if ((point.dy = point.y2 - point.y1) != 0)
			{
				if (point.dy > 0)
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
		}
	}
	return (0);
}

int		deal_key(int key, void *param)
{
	if (key || param)
		ft_putnbr(key);
	ft_putchar('\n');
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		size;
	t_point	point;

	if (argc != 2)
	{
		ft_putstr("usage : ./fdf <map>.fdf");
		exit(0);
	}
	point.x1 = 10;
	point.y1 = 10;
	point.x2 = 20;
	point.y2 = 20;
	size = ft_atoi(argv[1]);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, size, size, "test");
	draw_seg(point, mlx_ptr, win_ptr);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
