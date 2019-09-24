/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_options2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 12:35:31 by tigre             #+#    #+#             */
/*   Updated: 2019/08/03 20:56:58 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		usage(int *indicator, size_t *j)
{
	(*indicator) = 4;
	(*j)++;
	write(1, "\nUsage : -s print score", 23);
	write(1, "\n        -w print ways\n", 23);
}

void		print_score(int *indicator, size_t *j, t_data d)
{
	(*indicator) += 1;
	(*j)++;
	if (d.require_line)
	{
		write(1, "\n", 1);
		ft_putstr(d.require_line);
	}
	write(1, "\nscore : ", 9);
	if (d.start_end == 1)
		write(1, "1", 1);
	else
		ft_putnbr(d.score + 2);
	write(1, "\n", 1);
}

void		print_ways(int *indicator, size_t *j, t_data d)
{
	(*indicator) += 2;
	(*j)++;
	write(1, "\n", 1);
	ft_putstr(d.ways);
}
