/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:41:15 by tigre             #+#    #+#             */
/*   Updated: 2019/08/10 12:53:19 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		clean_buf(t_data *d)
{
	if (d->pad->sep->next->buf[0])
	{
		lstbufdel(&(d->pad->sep->next));
		d->pad->last = d->pad->sep;
		add_buf(&(d->pad));
	}
}

static void		ant_dispenser(t_sol **ant, t_sol **sol, t_data *d, int *n)
{
	int			i;

	i = 0;
	while (i < d->size && *n < d->nb_ant)
	{
		if (sol[i]->nb_ants > 0)
		{
			ant[(*n)++] = sol[i];
			sol[i]->nb_ants--;
		}
		i++;
	}
}

static t_sol	**init_ant(int *n, int *t, t_data *d, t_sol **sol)
{
	t_sol		**ant;
	int			i;

	i = 0;
	*n = 0;
	put_ways_to_buf(sol, d);
	clean_buf(d);
	if (!(ant = (t_sol**)malloc(sizeof(t_sol*) * d->nb_ant)))
		exit(1);
	while (i < d->nb_ant)
		ant[i++] = NULL;
	*t = d->score + 2;
	return (ant);
}

void			print_sol(t_sol **sol, t_data *d)
{
	int			i;
	int			n;
	t_sol		**ant;
	int			t;

	if (!(ant = init_ant(&n, &t, d, sol)))
		return ;
	while (t)
	{
		i = -1;
		while (++i < n)
			if (ant[i])
				ant[i] = ant[i]->next;
		ant_dispenser(ant, sol, d, &n);
		fill_buf(ant, n, d, d->pad);
		t--;
	}
	free(ant);
	if (d->start_end == 1)
		d->pad->last->buf[d->pad->last->len++] = '\n';
	d->pad->last->buf[d->pad->last->len] = '\0';
}
