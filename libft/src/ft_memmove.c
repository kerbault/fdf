/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:39:46 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 17:30:03 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*ret;

	ret = dest;
	if (dest < src)
		while ((size_t)(dest - ret) < n)
			*(t_byte *)dest++ = *(t_byte *)src++;
	else
		while (n--)
			((t_byte *)dest)[n] = ((t_byte *)src)[n];
	return (ret);
}
