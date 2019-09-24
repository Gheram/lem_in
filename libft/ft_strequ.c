/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:45:18 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/12 10:58:34 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_strequ(char const *s1, char const *s2)
{
	int i;
	int res;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break ;
		}
		i++;
	}
	res = s1[i] - s2[i];
	if (res == 0)
		return (1);
	return (0);
}
