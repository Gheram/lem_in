/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:59:52 by ghtouman          #+#    #+#             */
/*   Updated: 2019/08/03 16:49:02 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	update_tab_way(t_tree *t, t_way **tab_way, t_bool *old_visited)
{
	t_way	*tmp;
	int		mem;
	t_tree	*tmp2;

	mem = 0;
	tmp2 = t;
	while (tmp2)
	{
		tmp = tab_way[tmp2->id]->next;
		if (tmp2->id != 0)
			old_visited[tmp2->id] = 1;
		while (tmp)
		{
			if (tmp->id == mem)
				tmp->current += 1;
			if (tmp2->id != 0 && tmp->id == tmp2->father->id)
				tmp->current -= 1;
			tmp = tmp->next;
		}
		mem = tmp2->id;
		tmp2 = tmp2->father;
	}
}

void		get_flux(t_room **room, t_way **tab_way, t_data *d)
{
	t_tree	*t;
	t_bool	old_visited[d->nb_room + 1];
	t_tree	*bucheron[100000];

	d->bucheron = bucheron;
	d->i_bucheron = 0;
	d->score = -1;
	if (tab_way[0] == NULL)
		ft_exit(room, tab_way, *d);
	put_zero(old_visited, d->nb_room + 1);
	t = NULL;
	while (bfs(tab_way, &t, d, old_visited))
	{
		update_tab_way(t, tab_way, old_visited);
		clean_t_tree(d);
		potentiel_result(tab_way, d);
	}
	clean_t_tree(d);
}
