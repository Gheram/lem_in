/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:15:55 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/12 10:57:51 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		*ft_memdup(void const *content, size_t content_size)
{
	void *copy;

	if (content == NULL)
		return (NULL);
	if (!(copy = malloc(content_size)))
		return (NULL);
	ft_memcpy(copy, content, content_size);
	return (copy);
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list *my_list;

	if (!(my_list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		my_list->content = ft_memdup(content, content_size);
		my_list->content_size = content_size;
	}
	else
	{
		my_list->content = NULL;
		my_list->content_size = 0;
	}
	my_list->next = NULL;
	return (my_list);
}
