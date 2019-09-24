/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:10:39 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/08 21:01:31 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + i);
	while (i--)
	{
		if (s[i] == c)
			return ((char *)s + i);
	}
	return (NULL);
}
