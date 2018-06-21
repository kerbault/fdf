/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   keymap.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 16:40:59 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/21 16:16:56 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void ft_close(char *msg, int status)
{
	ft_putendl(msg);
	exit(status);
}

int	kf(int keycode, t_glob *glob)
{
	if (keycode == ESC)
		ft_close("Closing window", EXIT_SUCCESS);
	// if (keycode == 87)
	// 	ft_center();
	// if (keycode = 82)
	// 	ft_zero();
	else if (keycode == DECREASE)
		ft_decrease(glob);
	// if (keycode = 85)
	// 	ft_increase();
	// if (keycode = 91)
	// 	ft_up();
	// if (keycode = 84)
	// 	ft_down();
	// if (keycode = 86)
	// 	ft_left();
	// if (keycode = 88)
	// 	ft_right();
	// if (keycode = 69)
	// 	ft_zoomin();
	// if (keycode = 78)
	// 	ft_zoomout();
	return (0);
}
