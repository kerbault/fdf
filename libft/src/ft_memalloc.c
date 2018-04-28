/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:38:51 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 17:30:03 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/libft.h"

void		*ft_memalloc(size_t size)
{
	void	*ret;

	MALLOC_CHECK((ret = (void *)malloc(sizeof(*ret) * size)));
	ft_bzero(ret, size);
	return (ret);
}
