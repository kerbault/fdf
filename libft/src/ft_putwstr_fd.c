/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwstr_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:42:46 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 17:30:03 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/libft.h"

void		ft_putwstr_fd(wchar_t *s, const int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		ft_putwchar_fd(s[i++], fd);
}
