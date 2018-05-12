/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   keymap.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 16:40:59 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 16:41:27 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_close(char *msg, int status)
{
	ft_putendl(msg);
	exit(status);
}

int		kf(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		ft_close("Closing window", EXIT_SUCCESS);
	return (0);
}
