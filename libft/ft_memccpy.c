/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:04:30 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/12 10:58:01 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int				i;

	i = 0;
	s1 = (unsigned char*)dest;
	s2 = (unsigned char*)src;
	while (n--)
	{
		*s1 = *s2;
		if (*s1 == (unsigned char)c)
			return (dest + ++i);
		s1++;
		s2++;
		i++;
	}
	return (NULL);
}
