/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:10:14 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/12 11:00:38 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *alloc_str;

	if (!(alloc_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(alloc_str, 0, size);
	alloc_str[size] = '\0';
	return (alloc_str);
}
