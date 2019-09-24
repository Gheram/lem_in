/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:21:22 by tigre             #+#    #+#             */
/*   Updated: 2019/08/10 13:47:41 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		clean_room_list(t_room *room)
{
	t_room		*tmp;

	tmp = room;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		if (room->name)
			free(room->name);
		free(room);
		room = tmp;
	}
	room = NULL;
}

void			lstbufdel(t_buf **pad)
{
	t_buf		*tmp;
	t_buf		*next;

	if (*pad == NULL || pad == NULL)
		return ;
	tmp = *pad;
	while (tmp)
	{
		next = tmp->next;
		ft_bzero(tmp, sizeof(t_buf));
		free(tmp);
		tmp = next;
	}
	*pad = NULL;
}

void			free_room(t_room **room, t_data d)
{
	int			i;

	i = 0;
	if (room)
	{
		free(room['#']->name);
		free(room['#']);
		free(d.require_line);
		lstbufdel(&(d.pad));
		while (i < 127)
		{
			if (room[i] && i != '#')
				clean_room_list(room[i]);
			i++;
		}
		free(room);
	}
}
