/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwchar_fd.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 19:10:05 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 17:30:03 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_putwchar_fd(wchar_t wc, const int fd)
{
	size_t	ret;

	if (wc <= 127 && (ret = 1))
		ft_putchar_fd(wc, fd);
	else if (wc <= 2047 && (ret = 2))
	{
		ft_putchar_fd((wc >> 6) + 0xC0, fd);
		ft_putchar_fd((wc & 0x3F) + 0x80, fd);
	}
	else if (wc <= 65535 && (ret = 3))
	{
		ft_putchar_fd((wc >> 12) + 0xE0, fd);
		ft_putchar_fd(((wc >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((wc & 0x3F) + 0x80, fd);
	}
	else if (wc <= 1114111 && (ret = 4))
	{
		ft_putchar_fd((wc >> 18) + 0xF0, fd);
		ft_putchar_fd(((wc >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((wc >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((wc & 0x3F) + 0x80, fd);
	}
	return (ret);
}
