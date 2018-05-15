/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pers_iso.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 15:41:10 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 16:53:57 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	set_point1(int x, int y, int **map)
{
	t_point	p;

	p.x1 = (cos(0.3) * x * 20 - sin(0.3) * y * 20) + 60 * (W_WIDTH / 8)\
	- map[x][y];
	p.y1 = ((sin(0.3) * x * 25 + cos(0.3) * y * 25) + 60) - map[x][y];
	p.x2 = (cos(0.3) * (x + 1) * 20 - sin(0.3) * y * 20) + 60\
	* (W_WIDTH / 8) - map[x + 1][y];
	p.y2 = ((sin(0.3) * (x + 1) * 25 + cos(0.3) * y * 25) + 60) - map[x + 1][y];
	return (p);
}

t_point	set_point2(int x, int y, int **map)
{
	t_point	p;

	p.x1 = (cos(0.3) * x * 20 - sin(0.3) * y * 20) + 60 * (W_WIDTH / 8)\
	- map[x][y];
	p.y1 = ((sin(0.3) * x * 25 + cos(0.3) * y * 25) + 60) - map[x][y];
	p.x2 = (cos(0.3) * x * 20 - sin(0.3) * (y + 1) * 20) + 60\
	* (W_WIDTH / 8) - map[x][y + 1];
	p.y2 = ((sin(0.3) * x * 25 + cos(0.3) * (y + 1) * 25) + 60\
	- (map[x][y + 1]));
	return (p);
}
