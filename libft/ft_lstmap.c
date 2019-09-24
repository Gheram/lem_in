/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:06:24 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/10 17:32:00 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin_list;
	t_list *tmp;
	t_list *my_list;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	if (!(my_list = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	begin_list = my_list;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(my_list->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		my_list = my_list->next;
		lst = lst->next;
	}
	return (begin_list);
}
