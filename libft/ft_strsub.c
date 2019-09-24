/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:11:06 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/12 11:01:00 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*section;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(section = (char*)malloc(sizeof(*section) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
		section[i++] = (char)s[start++];
	section[i] = '\0';
	return (section);
}
