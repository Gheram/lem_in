/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:08:57 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/13 13:43:53 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t i;
	size_t taille_dest;

	taille_dest = ft_strlen(dest);
	i = 0;
	while (i < nb && src[i])
	{
		dest[taille_dest + i] = src[i];
		i++;
	}
	dest[taille_dest + i] = '\0';
	return (dest);
}
