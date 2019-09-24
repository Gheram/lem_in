/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:24:02 by ghtouman          #+#    #+#             */
/*   Updated: 2019/06/13 10:09:19 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **begin_list, void *content)
{
	t_list *element;
	t_list *temporaire;

	if (begin_list == NULL)
		return ;
	if ((element = ft_create_elem(content)) == NULL)
		return ;
	if (*begin_list == NULL)
	{
		*begin_list = element;
		return ;
	}
	temporaire = *begin_list;
	while (temporaire->next != NULL)
		temporaire = temporaire->next;
	temporaire->next = element;
}
