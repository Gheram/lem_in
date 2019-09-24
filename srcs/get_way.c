/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_way.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:10:26 by ghtouman          #+#    #+#             */
/*   Updated: 2019/08/03 21:54:48 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Mettre les pointeur src et dst sur les salles correspondantes dans la liste
** t_room pour acceder plus simplement au informations en comparant la taille
** puis la string pour etre plus opti
*/

static int		find_room(char *line, t_room **room, t_room **src, t_room **dst)
{
	char		*s;
	char		*d;
	t_room		*tmp;

	s = line;
	while (*line && *line != '-')
		line++;
	if (*line != '-')
		return (0);
	d = line + 1;
	*line = '\0';
	tmp = room[(int)s[0]];
	while (tmp && ft_strcmp(tmp->name, s))
		tmp = tmp->next;
	tmp ? *src = tmp : tmp;
	if (!tmp)
		return (0);
	tmp = room[(int)d[0]];
	while (tmp && ft_strcmp(tmp->name, d))
		tmp = tmp->next;
	if (tmp)
		*dst = tmp;
	else
		return (0);
	return (1);
}

/*
** Cree les maillons et les range dans le tableau de liste par id
*/

static void		new_way(t_way **tab_way, t_room *src, t_room *dst)
{
	t_way		*tmp;
	t_way		*elem;

	if (!(elem = (t_way*)malloc(sizeof(t_way))))
		exit(1);
	elem->id = dst->id;
	elem->name = dst->name;
	elem->current = 0;
	elem->next = NULL;
	if (tab_way[src->id] == NULL)
	{
		if (!(tmp = (t_way*)malloc(sizeof(t_way))))
			exit(1);
		tmp->id = src->id;
		tmp->name = src->name;
		tmp->current = 0;
		tmp->next = NULL;
		tab_way[src->id] = tmp;
	}
	else
		tmp = tab_way[src->id]->last;
	tmp->next = elem;
	tab_way[src->id]->last = elem;
}

/*
** Cree le tableau de listes, chaque case du tableau est le premier maillon
** d'une liste qui represente une des pieces, les autres maillons sont toutes
** les autres pieces a laquelle la premiere est reliee
*/

static t_way	**exit_get_way(t_way **tab_way, char **line)
{
	ft_strdel(line);
	return (tab_way);
}

static t_way	**add_way(t_way **tab_way, t_room *src, t_room *dst)
{
	new_way(tab_way, src, dst);
	new_way(tab_way, dst, src);
	return (tab_way);
}

t_way			**get_way(char **line, t_data *d,
							t_way **tab_way, t_room **room)
{
	t_room		*src;
	t_room		*dst;

	tab_way = init_get_way(tab_way, d);
	d->pad = lst_buf(*line, d->pad);
	if (check_ascii(*line) != -1 && find_room(*line, room, &src, &dst))
		tab_way = add_way(tab_way, src, dst);
	else
		return (exit_get_way(tab_way, line));
	ft_strdel(line);
	while (get_next_line(0, line))
	{
		if (((d->pad = lst_buf(*line, d->pad)) || 1) && *line[0] != '#')
		{
			if (check_ascii(*line) != -1 && find_room(*line, room, &src, &dst))
				tab_way = add_way(tab_way, src, dst);
			else
				return (exit_get_way(tab_way, line));
		}
		else if (no_start_end(*line))
			return (exit_get_way(tab_way, line));
		ft_strdel(line);
	}
	new_way(tab_way, room['#']->last, room['#']->last);
	return (exit_get_way(tab_way, line));
}
