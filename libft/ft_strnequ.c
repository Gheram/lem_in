/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:10:03 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/10 17:24:48 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	int		res;

	if (!s1 || !s2)
		return (0);
	i = 0;
	if (n == 0)
		return (1);
	while (i < n - 1 && s1[i] && s1[i] == s2[i])
		i++;
	res = s1[i] - s2[i];
	if (res == 0)
		return (1);
	return (0);
}
