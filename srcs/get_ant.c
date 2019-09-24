/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <tigre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:07:05 by tigre             #+#    #+#             */
/*   Updated: 2019/08/03 22:16:28 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	check_int(char *line)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	if (!line)
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
	{
		if (i <= 11)
			nb = nb * 10 + (line[i] - '0');
		i++;
	}
	if (line[i] != '\0')
		return (-1);
	if (nb <= 2147483647 && nb >= 0)
		return ((int)nb);
	else if (nb > 2147483647)
		return (2147483647);
	else
		return (-1);
}

void		get_ant(char **line, t_data *d)
{
	while (get_next_line(0, line))
	{
		if (!(*line) || !line)
		{
			ft_strdel(line);
			ft_exit(NULL, NULL, *d);
		}
		if ((d->nb_ant = check_int(*line)) > 0)
		{
			d->pad = lst_buf(*line, d->pad);
			return (ft_strdel(line));
		}
		else
		{
			ft_strdel(line);
			ft_exit(NULL, NULL, *d);
		}
		ft_strdel(line);
	}
}
