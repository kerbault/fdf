/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cav.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 15:40:37 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 15:44:44 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	set_cav1(int x, int y, int **map, size_t i)
{
	t_point	p;
	int		decal;
	int		ratio;

	ratio = 2;
	decal = 200;
	p.x1 = (x * 70) - i + decal;
	p.y1 = (y * 70) - (map[x][y]) * ratio + decal;
	p.x2 = ((x + 1) * 70) - i + decal;
	p.y2 = (y * 70) - (map[x + 1][y] * ratio) + decal;
	return (p);
}

t_point	set_cav2(int x, int y, int **map, size_t i)
{
	t_point	p;
	int		decal;
	int		ratio;

	ratio = 2;
	decal = 200;
	p.x1 = (x * 70) - i + decal;
	p.y1 = (y * 70) - (map[x][y]) * ratio + decal;
	p.x2 = (x * 70) - i - 10 + decal;
	p.y2 = ((y + 1) * 70) - (map[x][y + 1] * ratio) + decal;
	return (p);
}
