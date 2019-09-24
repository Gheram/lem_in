/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:04:10 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/12 10:57:20 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	size_t		i;
	long int	nb;

	nb = (long int)n;
	len = ft_intlen(nb);
	if (!(str = (char*)(malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	str[len] = '\0';
	i = 0;
	if (nb < 0)
	{
		str[i++] = '-';
		nb = -nb;
	}
	while (i < len)
	{
		str[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}
