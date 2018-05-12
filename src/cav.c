/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cav.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 15:40:37 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 18:27:46 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	set_cav1(int x, int y, int **map, size_t i)
{
	t_point	pt;
	int		decal;
	int		ratio;

	ratio = 2;
	decal = 200;
	pt.x1 = (x * 70) - i + decal;
	pt.y1 = (y * 70) - (map[x][y]) * ratio + decal;
	pt.x2 = ((x + 1) * 70) - i + decal;
	pt.y2 = (y * 70) - (map[x + 1][y] * ratio) + decal;
	return (pt);
}

t_point	set_cav2(int x, int y, int **map, size_t i)
{
	t_point	pt;
	int		decal;
	int		ratio;

	ratio = 2;
	decal = 200;
	pt.x1 = (x * 70) - i + decal;
	pt.y1 = (y * 70) - (map[x][y]) * ratio + decal;
	pt.x2 = (x * 70) - i - 10 + decal;
	pt.y2 = ((y + 1) * 70) - (map[x][y + 1] * ratio) + decal;
	return (pt);
}
