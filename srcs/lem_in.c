/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:01:01 by ghtouman          #+#    #+#             */
/*   Updated: 2019/08/09 16:57:32 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h>

void			ft_exit(t_room **room, t_way **tab_way, t_data d)
{
	write(2, "ERROR\n", 6);
	clean(room, tab_way, d);
	exit(1);
}

void			print_map(t_buf *pad)
{
	t_buf	*tmp;

	tmp = pad;
	while (tmp)
	{
		write(1, tmp->buf, tmp->len);
		tmp = tmp->next;
	}
}

/*
**	la variable d.off_s_e sert à déterminer si start et end existent
*/

static void		init_data(t_data *d, t_room ***room, t_way ***tab_way)
{
	ft_bzero(d, sizeof(t_data));
	*tab_way = NULL;
	*room = NULL;
}

int				main(int ac, char **av)
{
	char		*line;
	t_data		d;
	t_room		**room;
	t_way		**tab_way;

	init_data(&d, &room, &tab_way);
	get_ant(&line, &d);
	room = get_room(&line, room, &d);
	if (d.off_s_e == 3)
	{
		tab_way = get_way(&line, &d, tab_way, room);
		d.pad = lst_buf("\0", d.pad);
		d.pad->sep = d.pad->last;
		add_buf(&d.pad);
		d.pad->sep->next->buf[0] = '\0';
		get_flux(room, tab_way, &d);
	}
	if (d.score == -1)
		ft_exit(room, tab_way, d);
	print_map(d.pad);
	if (ac >= 2)
		print_options(d, ac, av);
	clean(room, tab_way, d);
	return (0);
}
