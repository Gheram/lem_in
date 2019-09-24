/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:01:21 by tigre             #+#    #+#             */
/*   Updated: 2019/08/10 12:50:39 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		add_room(t_file **f, int id, t_tree *t, int true_father)
{
	t_file		*elem;
	t_file		*tmp;

	tmp = *f;
	if (!(elem = (t_file*)malloc(sizeof(t_file))))
		exit(1);
	elem->id = id;
	elem->father = t;
	elem->true_father = true_father;
	elem->next = NULL;
	if (id == 0)
		*f = elem;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}

static void		add_branch(t_tree **t, int id, t_tree *father, t_data *d)
{
	t_tree		*elem;

	if (!(elem = (t_tree*)malloc(sizeof(t_tree))))
		exit(1);
	elem->id = id;
	elem->father = father;
	if (father == NULL)
	{
		elem->step = 0;
		elem->current = 1;
	}
	else
	{
		elem->step = father->step + 1;
		elem->current = 1;
	}
	d->bucheron[d->i_bucheron] = elem;
	d->i_bucheron++;
	*t = elem;
}

static t_bool	check_current(t_way *child, t_bool *overlap)
{
	t_bool		ret;

	ret = true;
	if (child->current == 1)
		ret = false;
	else if (child->current == 0 && *overlap == true)
		ret = false;
	return (ret);
}

static t_bool	find_room(t_bfs *bfs, t_tree **t, t_way **tab_way, t_data *d)
{
	t_way		*tmp;

	tmp = tab_way[bfs->f->id]->next;
	if (bfs->f->id != 0)
		bfs->overlap = go_back(bfs, tab_way);
	while (tmp)
	{
		if (check_current(tmp, &(bfs->overlap)) && tab_way[tmp->id]
				&& bfs->visited[tmp->id] == 0)
		{
			add_branch(t, tmp->id, bfs->f->father, d);
			add_room(&(bfs->f), tmp->id, *t, bfs->f->id);
		}
		else if (bfs->p_old_visited[tmp->id] == false && bfs->overlap == false)
			bfs->visited[tmp->id] = true;
		if (tmp->id == d->end_id && tmp->current != 1)
		{
			add_branch(t, tmp->id, bfs->f->father, d);
			return (true);
		}
		tmp = tmp->next;
	}
	return (false);
}

t_bool			bfs(t_way **tab_way, t_tree **t, t_data *d, t_bool *old_visited)
{
	t_bfs		bfs;

	bfs.overlap = false;
	bfs.p_old_visited = old_visited;
	if (!(bfs.visited = (t_bool*)malloc(sizeof(t_bool) * (d->nb_room + 1))))
		exit(1);
	put_zero(bfs.visited, d->nb_room + 1);
	add_branch(t, 0, NULL, d);
	add_room(&(bfs.f), 0, *t, 0);
	d->file = bfs.f;
	while (bfs.f != NULL)
	{
		bfs.visited[bfs.f->id] = true;
		if ((bfs.stop = find_room(&bfs, t, tab_way, d)))
			break ;
		bfs.f = bfs.f->next;
	}
	clean_file(d->file);
	free(bfs.visited);
	return (bfs.stop);
}
