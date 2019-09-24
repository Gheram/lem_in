/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:16:49 by tigre             #+#    #+#             */
/*   Updated: 2019/08/03 20:52:54 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			print_options(t_data d, int ac, char **av)
{
	size_t		i;
	size_t		j;
	int			indicator;

	i = 0;
	indicator = 0;
	while (i < (size_t)ac && av[i])
	{
		j = 1;
		if (av[i][0] == '-')
		{
			if (av[i][j] == 'h' && !(indicator & 4))
				usage(&indicator, &j);
			if (av[i][j] == 's' && !(indicator & 1))
				print_score(&indicator, &j, d);
			if (av[i][j] == 'w' && !(indicator & 2))
				print_ways(&indicator, &j, d);
		}
		i++;
	}
}

static void		init_way(char *str, int *index, int *len)
{
	int			i;

	i = 0;
	*index = -1;
	*len = 0;
	while (str[i])
		str[i++] = '\0';
}

void			str_to_buf(t_data *d, int *len, char *str)
{
	while (*str)
	{
		d->ways[*len] = *str;
		(*len)++;
		str++;
	}
}

void			put_ways_to_buf(t_sol **sol, t_data *d)
{
	int			i;
	int			len;
	t_sol		*tmp;
	char		*str;

	d->ways[0] = 0;
	init_way(d->ways, &i, &len);
	while (++i < d->size)
	{
		tmp = sol[i];
		str_to_buf(d, &len, "[chemin ");
		str = ft_itoa(i);
		str_to_buf(d, &len, str);
		str_to_buf(d, &len, "] :\n");
		while (tmp)
		{
			str_to_buf(d, &len, tmp->name);
			tmp->next ? str_to_buf(d, &len, " -> ") : tmp;
			tmp = tmp->next;
		}
		str_to_buf(d, &len, "\n");
		free(str);
	}
	d->ways[len] = '\0';
}

void			get_line_require(char *line, t_data *d)
{
	if ((ft_strncmp(line, "#Here is the number of lines required:", 38)) == 0)
		d->require_line = ft_strdup(line);
	else
		d->require_line = NULL;
	d->first = 0;
}
