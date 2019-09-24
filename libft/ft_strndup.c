/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:22:03 by ghtouman          #+#    #+#             */
/*   Updated: 2019/07/23 12:28:36 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dest;
	size_t	i;
	size_t	size;

	size = ft_strlen(s1);
	if (size < n)
	{
		if ((dest = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
			return (NULL);
	}
	else
	{
		if ((dest = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
			return (NULL);
	}
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
