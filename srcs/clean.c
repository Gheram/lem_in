/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:43:19 by tigre             #+#    #+#             */
/*   Updated: 2019/08/10 13:14:04 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			clean_t_tree(t_data *d)
{
	while (d->i_bucheron > 0)
	{
		d->i_bucheron--;
		free(d->bucheron[d->i_bucheron]);
	}
}

void			clean_sol(t_sol **sol, int size)
{
	int			i;
	t_sol		*tmp;

	i = 0;
	while (i < size)
	{
		if (sol[i])
		{
			tmp = sol[i];
			while (tmp)
			{
				tmp = tmp->next;
				sol[i]->name = NULL;
				free(sol[i]);
				sol[i] = tmp;
			}
			sol[i] = NULL;
		}
		i++;
	}
	free(sol);
}

static void		clean_tab_way_list(t_way *tab_way)
{
	t_way		*tmp;

	tmp = tab_way;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		tab_way->name = NULL;
		free(tab_way);
		tab_way = tmp;
	}
	tab_way = NULL;
}

void			clean(t_room **room, t_way **tab_way, t_data d)
{
	int			i;

	i = 0;
	free_room(room, d);
	if (d.off_s_e == 3 && tab_way)
	{
		i = 0;
		while (i < d.nb_room)
		{
			if (tab_way[i])
				clean_tab_way_list(tab_way[i]);
			i++;
		}
		free(tab_way);
	}
}
