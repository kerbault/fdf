/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 13:44:30 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 17:30:03 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_mallsize(int value, int base)
{
	int		ret;

	ret = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value /= base;
		ret++;
	}
	return (ret);
}

char	*ft_itoa_base(int value, int base)
{
	char	*ret;
	char	*tab;
	long	tmp;
	int		bol;
	size_t	size;

	tab = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	tmp = (long)value;
	bol = 0;
	if (base < 2 || base > 36)
		return (NULL);
	if (value < 0 && (tmp = -tmp))
		if (base == 10)
			bol = 1;
	size = ft_mallsize(tmp, base);
	MALLOC_CHECK((ret = (char*)malloc(sizeof(char) * (size + bol + 1))));
	ret[size + bol] = '\0';
	if (bol == 1)
		ret[0] = '-';
	if (tmp == 0)
		ret[0] = '0';
	tmp *= base;
	while (tmp > 0 && (tmp /= base) && size--)
		ret[size + bol] = tab[tmp % base];
	return (ret);
}
