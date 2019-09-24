/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_the_rabbit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:39:22 by tigre             #+#    #+#             */
/*   Updated: 2019/08/10 12:51:25 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		min_path(t_way **tab_way)
{
	int			min;
	t_way		*start;

	start = tab_way[0];
	min = 0;
	start = start->next;
	while (start)
	{
		if (start->current == 1)
			min++;
		start = start->next;
	}
	return (min);
}

static void		add_way(char *name, t_sol **sol, int i)
{
	t_sol		*elem;
	t_sol		*tmp;

	if (!(elem = (t_sol*)malloc(sizeof(t_sol))))
		exit(1);
	elem->name = name;
	elem->nb_ants = 0;
	elem->next = NULL;
	if (sol[i] == NULL)
	{
		elem->len_way = 0;
		sol[i] = elem;
	}
	else
	{
		sol[i]->len_way++;
		tmp = sol[i];
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = elem;
	}
}

static t_sol	**init_sol(t_rabbit *rabbit, t_way **tab_way,
										t_sol **sol, t_data *d)
{
	rabbit->id = 0;
	d->size = min_path(tab_way);
	if (!(sol = (t_sol**)malloc(sizeof(t_sol*) * (d->size + 1))))
		exit(1);
	rabbit->i = d->size;
	while (rabbit->i >= 0)
		sol[rabbit->i--] = NULL;
	rabbit->tmp = tab_way[rabbit->id];
	rabbit->tmp = rabbit->tmp->next;
	rabbit->i = 0;
	return (sol);
}

t_sol			**follow_the_rabbit(t_way **tab_way, t_sol **sol, t_data *d)
{
	t_rabbit	rabbit;

	sol = init_sol(&rabbit, tab_way, sol, d);
	while (rabbit.tmp && rabbit.i < d->size)
	{
		if (rabbit.tmp->current == 1)
		{
			(rabbit.id == 0) ? rabbit.mem = rabbit.tmp : rabbit.mem;
			add_way(rabbit.tmp->name, sol, rabbit.i);
			if (rabbit.tmp->id == d->end_id && rabbit.i++ < d->size)
			{
				rabbit.id = 0;
				rabbit.tmp = rabbit.mem;
				(rabbit.tmp->next) ? rabbit.tmp = rabbit.tmp->next : rabbit.tmp;
			}
			else
			{
				rabbit.id = rabbit.tmp->id;
				rabbit.tmp = tab_way[rabbit.id];
			}
		}
		else
			rabbit.tmp = rabbit.tmp->next;
	}
	return (sol);
}
