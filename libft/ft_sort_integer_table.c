/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:19:42 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/12 11:34:59 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int j;
	int transfere;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				transfere = tab[i];
				tab[i] = tab[j];
				tab[j] = transfere;
			}
			j++;
		}
		i++;
	}
}
