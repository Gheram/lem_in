/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:30:04 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/12 11:32:17 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_create_elem(void *content)
{
	t_list *struc;

	if (!(struc = malloc(sizeof(*struc))))
		return (NULL);
	struc->content = content;
	struc->next = NULL;
	return (struc);
}
