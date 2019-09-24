/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:25:42 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/12 11:31:30 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_front(t_list **begin_list, void *content)
{
	t_list *element;

	if (begin_list && (element = ft_create_elem(content)))
	{
		element->next = *begin_list;
		*begin_list = element;
	}
}
