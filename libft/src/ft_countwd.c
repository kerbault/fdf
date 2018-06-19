/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countwd.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 19:23:21 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 21:29:13 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_countwd(char const *s)
{
	size_t		nb;
	size_t		i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != ' ' && s[i] != '\t')
			nb++;
		if (s[i] != ' ' && s[i] != '\t' && ((i > 0 && s[i - 1] == ' ') ||\
		(i > 0 && s[i - 1] == '\t')))
			nb++;
		i++;
	}
	return (nb);
}
