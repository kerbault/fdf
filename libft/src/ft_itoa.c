/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:38:04 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 17:58:55 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	*ft_minint(void)
{
	char	*min;

	MALLOC_CHECK((min = ft_strnew(11)));
	min = ft_strdup("-2147483648\0");
	return (min);
}

static int	ft_countnumb(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n > 0)
	{
		while (n > 0)
		{
			n /= 10;
			i++;
		}
		return (i + 1);
	}
	return (2);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*ret;

	i = ft_countnumb(n);
	if (n == -2147483648)
		return (ft_minint());
	MALLOC_CHECK((ret = ft_strnew(i)));
	if (n == 0)
		return (ft_strdup("0\0"));
	if (n < 0)
	{
		ret[0] = '-';
		n = -n;
	}
	ret[--i] = '\0';
	i--;
	while (n > 0)
	{
		ret[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (ret);
}
