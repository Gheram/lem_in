/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:08:16 by ghtouman          #+#    #+#             */
/*   Updated: 2018/06/01 16:01:08 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_concat;
	char	*concat;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_concat = ft_strlen(s1) + ft_strlen(s2);
	if (!(concat = (char*)malloc(sizeof(*concat) * (len_concat + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		concat[i] = s1[i];
	while (s2[j])
		concat[i++] = s2[j++];
	concat[i] = '\0';
	return (concat);
}
