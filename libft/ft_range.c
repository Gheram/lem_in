/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:03:30 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/12 11:03:46 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		i;
	int		*range;

	i = 0;
	range = NULL;
	if (min < max)
	{
		range = (int*)malloc(sizeof(*range) * (max - min));
		if (range == NULL)
			return (NULL);
		while (min < max)
		{
			range[i] = min;
			i++;
			min++;
		}
	}
	return (range);
}
