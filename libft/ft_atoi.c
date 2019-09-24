/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:03:19 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/13 14:30:23 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int			nega;
	long int	nb;
	int			i;

	nega = 1;
	nb = 0;
	i = 0;
	while ((*str >= 0 && *str <= 26) || (*str >= 28 && *str <= 32))
		str++;
	if (str[0] == '+' && str[1] == '-')
		return (0);
	if (*str == '-')
		nega = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
		i++;
	}
	(i > 19 && nega == 1) ? nb = -1 : 0;
	(i > 19 && nega == -1) ? nb = 0 : 0;
	return (nb * nega);
}
