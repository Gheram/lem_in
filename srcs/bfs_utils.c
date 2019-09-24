/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:36:20 by tigre             #+#    #+#             */
/*   Updated: 2019/08/01 18:20:54 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		put_zero(t_bool *tab, int size)
{
	size--;
	while (size >= 0)
		tab[size--] = false;
}

t_bool		go_back(t_bfs *bfs, t_way **tab_way)
{
	t_way	*tmp;
	int		here;
	int		before;

	here = bfs->f->id;
	before = bfs->f->true_father;
	tmp = tab_way[before];
	while (tmp && tmp->id != here)
		tmp = tmp->next;
	if (tmp->current == 0 && bfs->p_old_visited[here] == true)
		return (true);
	return (false);
}

void		clean_file(t_file *f)
{
	t_file	*tmp;

	tmp = f;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(f);
		f = tmp;
	}
	f = NULL;
}
