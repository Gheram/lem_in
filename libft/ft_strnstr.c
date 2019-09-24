/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:10:25 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/13 13:46:53 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = -1;
	while (s1[++i] && i < len)
	{
		j = 0;
		while (s1[i + j] && s2[j] && s1[i + j] == s2[j] && i + j < len)
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
	}
	return (NULL);
}
