/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:44:46 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 19:30:42 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s)
		return (ft_strdup("\0"));
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	i = 0;
	while (len && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	{
		len--;
		i++;
	}
	MALLOC_CHECK((str = ft_strnew(len)));
	s += i;
	i = 0;
	while (i < len)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}
