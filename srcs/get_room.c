/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:16:23 by tigre             #+#    #+#             */
/*   Updated: 2019/08/10 13:01:07 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_bool	new_elem(char *line, t_room **room, t_data *d)
{
	t_room		*elem;

	if (!(elem = (t_room*)malloc(sizeof(t_room))))
		exit(1);
	if (!(elem->name = strdup_lim(line, d, &elem, room)))
		exit(1);
	elem->next = NULL;
	elem->id = d->nb_room;
	if (room[(int)line[0]] == NULL)
	{
		room[(int)line[0]] = elem;
		elem->last = elem;
	}
	else
	{
		room[(int)line[0]]->last->next = elem;
		room[(int)line[0]]->last = elem;
	}
	d->nb_room++;
	return (false);
}

static t_bool	forge_list(t_room **room, t_data *d, char *line, int *mem)
{
	if (d->check == 1)
	{
		*mem = d->nb_room;
		d->nb_room = 0;
	}
	if (new_elem(line, room, d))
		return (true);
	if (d->check == 1)
	{
		room['#']->next = room[(int)line[0]]->last;
		d->off_s_e += d->check;
	}
	d->check == 1 ? d->start = room[(int)line[0]]->last->name : d->start;
	d->check == 2 ? d->end = room[(int)line[0]]->last->name : d->end;
	if (d->check == 2)
	{
		room['#']->last = room[(int)line[0]]->last;
		d->off_s_e += d->check;
	}
	return (false);
}

static t_bool	kill_the_norme(char *line, t_room **room, t_data *d)
{
	int			mem;

	if (check_ascii(line) == -1)
		return (true);
	if (line[0] == '#' && line[1] == '#')
	{
		if (d->off_s_e == 3)
			return (true);
		else if (!(ft_strcmp(line + 2, "start")))
			d->check = 1;
		else if (!(ft_strcmp(line + 2, "end")))
			d->check = 2;
	}
	if (line[0] != '#')
	{
		if (no_double_room(room, line))
			return (true);
		if (forge_list(room, d, line, &mem))
			return (true);
		d->check == 1 ? d->nb_room = mem : 0;
		d->check = 0;
	}
	return (false);
}

static t_room	**init_room(t_room **room, t_data *d)
{
	int			i;

	i = 0;
	d->nb_room = 1;
	d->check = 0;
	d->first = 1;
	if (!(room = (t_room**)malloc(sizeof(t_room*) * 127)))
		exit(1);
	while (i < 127)
		room[i++] = NULL;
	if (!(room['#'] = (t_room*)malloc(sizeof(t_room))))
		exit(1);
	room['#']->name = ft_strdup("start_end");
	room['#']->id = -1;
	return (room);
}

t_room			**get_room(char **line, t_room **room, t_data *d)
{
	if (!(room = init_room(room, d)))
		ft_exit(room, NULL, *d);
	while (get_next_line(0, line))
	{
		d->first ? get_line_require(*line, d) : d;
		if (*line[0] != '#' && find_dash(*line))
		{
			if (d->check)
				end_get_room(room, line, d);
			d->check = 1;
			break ;
		}
		if (kill_the_norme(*line, room, d))
			end_get_room(room, line, d);
		d->pad = lst_buf(*line, d->pad);
		ft_strdel(line);
	}
	d->nb_room++;
	if (!d->check || d->off_s_e != 3)
		end_get_room(room, line, d);
	else
		d->end_id = room['#']->last->id;
	return (room);
}
