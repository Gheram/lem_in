/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkspaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:13:11 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/12 10:29:51 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_checkspaces(const char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[j])
	{
		while ((str[j] == '\n' || str[j] == '\t' || str[j] == 32)
				&& str[j] != '\0')
		{
			i++;
			j++;
		}
		while (str[j] != 32 && str[j] != '\t' && str[j] != '\n'
				&& str[j] != '\0')
			j++;
	}
	return (i);
}
