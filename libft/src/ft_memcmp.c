/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:39:31 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 17:30:03 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_byte	*s_1;
	t_byte	*s_2;

	s_1 = (t_byte*)s1;
	s_2 = (t_byte*)s2;
	while (n--)
		if (*s_1++ != *s_2++)
			return (*--s_1 - *--s_2);
	return (0);
}
