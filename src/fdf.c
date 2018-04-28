/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 14:41:15 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 17:19:58 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

// int		draw_seg2(int x1, int y1, int x2, int y2, int dx, int dy, void *mlx_ptr, void *win_ptr)
// {
// 	int		e;

// 	e = dx;
// 	dx *= 2;
// 	dy *= 2;
// 	while (1)
// 	{
// 		mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
// 		if ((x1 += 1) == x2)
// 			break ;
// 		if ((e -= dy) < 0)
// 		{
// 			y1 += 1;
// 			e += dx;
// 		}
// 	}
// }

int		draw_seg(int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr)
{
	int		dx;
	int		dy;
	int		e;

	if ((dx = x2 - x1) != 0)
	{
		if (dx > 0)
		{
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx *= 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
							if ((x1 += 1) == x2)
								break ;
							if ((e -= dy) < 0)
							{
								y1 += 1;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy *= 2;
						dx *= 2;
						while (1)
						{
							mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
							if ((y1 += 1) == y2)
								break ;
							if ((e -= dy) < 0)
							{
								x1 += 1;
								e += dy;
							}
						}
					}
				}
				else if (dy < 0)
				{
					if (dx >= -dy)
					{
						e = dx;
						dx *= 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
							if ((x1 += 1) == x2)
								break ;
							if ((e -= dy) < 0)
							{
								y1 += 1;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy *= 2;
						dx *= 2;
						while (1)
						{
							mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
							if ((y1 -= 1) == y2)
								break ;
							if ((e += dx) > 0)
							{
								x1 += 1;
								e += dy;
							}
						}
					}
				}
				else
					while (x1 + 1 != x2)
					{
						mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
						x1 += 1;
					}
			}
		}
		else if (dx < 0)
		{
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
					{
						e = dx;
						dx *= 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
							if ((x1 -= 1) == x2)
								break ;
							if ((e += dy) >= 0)
							{
								y1 += 1;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy *= 2;
						dx *= 2;
						while (1)
						{
							mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
							if ((y1 += 1) == y2)
								break ;
							if ((e += dx) <= 0)
							{
								x1 += 1;
								e += dy;
							}
						}
					}
				}
				else if (dy < 0)
				{
					if (dx <= dy)
					{
						e = dx;
						dx *= 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
							if ((x1 -= 1) == x2)
								break ;
							if ((e -= dy) >= 0)
							{
								y1 -= 1;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy *= 2;
						dx *= 2;
						while (1)
						{
							mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
							if ((y1 -= 1) == y2)
								break ;
							if ((e -= dx) >= 0)
							{
								x1 -= 1;
								e += dy;
							}
						}
					}
				}
				else
					while (x1 - 1 != x2)
					{
						mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
						x1 -= 1;
					}
			}
		}
		else
		{
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0)
					while (y1 + 1 != y2)
					{
						mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
						y1 += 1;
					}
				if (dy < 0)
					while (y1 - 1 != y2)
					{
						mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
						y1 -= 1;
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

	if (argc != 2)
	{
		ft_putstr("usage : ./fdf <map>.fdf");
		exit(0);
	}
	size = ft_atoi(argv[1]);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, size, size, "test");
	draw_seg(100, 100, 3, 3, mlx_ptr, win_ptr);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
