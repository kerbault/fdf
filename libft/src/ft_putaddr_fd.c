/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putaddr_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:40:45 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 17:30:03 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/libft.h"

void					ft_putaddr_fd(void *ptr, int fd)
{
	long int			div;
	char				tmp;
	unsigned long int	n;

	n = (unsigned long int)ptr;
	div = 16;
	ft_putstr_fd("0x", fd);
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		tmp = '0' + n / div;
		if (tmp > '9')
		{
			tmp += 39;
			write(fd, &tmp, 1);
		}
		else
			write(fd, &tmp, 1);
		n %= div;
		div /= 16;
	}
}
