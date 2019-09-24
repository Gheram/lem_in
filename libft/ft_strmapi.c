/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:08:44 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/10 17:22:06 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*str;
	size_t		len;
	size_t		i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (!(str = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = f(i, s[i]);
	return (str);
}
