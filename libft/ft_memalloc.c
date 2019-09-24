/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:04:25 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/12 10:57:56 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *alloc;

	if (size > 4294967295)
		return (NULL);
	if (!(alloc = malloc(sizeof(*alloc) * (size + 1))))
		return (NULL);
	ft_memset(alloc, 0, size);
	return (alloc);
}
