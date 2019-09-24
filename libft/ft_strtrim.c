/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:11:17 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/12 11:01:18 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_strsub_bis(char const *s, unsigned int start, size_t len)
{
	char	*section;
	size_t	i;

	if (!(section = (char*)malloc(sizeof(*section) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
		section[i++] = (char)s[start++];
	section[i] = '\0';
	return (section);
}

char			*ft_strtrim(char const *s)
{
	char const		*len;
	char			*copy;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	len = s + ft_strlen(s) - 1;
	while (*len == ' ' || *len == '\n' || *len == '\t')
		len--;
	copy = ft_strsub_bis(s, 0, len - s + 1);
	return (copy);
}
