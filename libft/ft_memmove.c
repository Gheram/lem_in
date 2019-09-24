/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:05:23 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/12 11:00:12 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (str2 < str1)
	{
		while (n--)
			str1[n] = str2[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
