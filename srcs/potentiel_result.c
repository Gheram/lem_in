/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   potentiel_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:05:18 by ghtouman          #+#    #+#             */
/*   Updated: 2019/07/31 14:51:41 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	ft_sort_integer_table_list(t_sol **sol, int size)
{
	int		i;
	int		j;
	t_sol	*tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (sol[i] && sol[j] && sol[i]->len_way > sol[j]->len_way)
			{
				tmp = sol[i];
				sol[i] = sol[j];
				sol[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	manage_ants(t_sol **sol, int ants, int size)
{
	int		i;
	int		score;
	int		psize;

	while (ants)
	{
		i = 0;
		while (sol[i] && ants && i < size)
		{
			psize = sol[i]->len_way;
			if (i == 0)
			{
				++(sol[i]->nb_ants);
				--ants;
				score = psize + sol[i]->nb_ants - 2;
			}
			else if (score >= (psize - 1))
			{
				++(sol[i]->nb_ants);
				--ants;
			}
			i++;
		}
	}
	return (score);
}

void		potentiel_result(t_way **tab_way, t_data *d)
{
	t_sol	**sol;
	int		i;
	t_way	**tmp;
	int		score;

	tmp = tab_way;
	sol = NULL;
	sol = follow_the_rabbit(tmp, sol, d);
	i = -1;
	while (++i < d->size)
		ft_sort_integer_table_list(sol, d->size);
	if (sol[0]->len_way == 0 && ft_strcmp(sol[0]->name, d->end) == 0)
		d->start_end = 1;
	score = manage_ants(sol, d->nb_ant, d->size);
	if (d->score == -1)
	{
		d->score = score;
		print_sol(sol, d);
	}
	if (score < d->score)
	{
		d->score = score;
		print_sol(sol, d);
	}
	clean_sol(sol, d->size);
}
