/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 22:23:12 by tigre             #+#    #+#             */
/*   Updated: 2019/08/10 13:01:21 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_bool		no_double_room(t_room **room, char *line)
{
	t_room	*tmp;
	size_t	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	tmp = room[(int)line[0]];
	while (tmp)
	{
		if (ft_strlen(tmp->name) == i)
			if (ft_strncmp(tmp->name, line, i) == 0)
				return (true);
		tmp = tmp->next;
	}
	return (false);
}

t_bool		no_start_end(char *line)
{
	t_bool	ret;

	ret = false;
	if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
		ret = true;
	return (ret);
}

void		end_get_room(t_room **room, char **line, t_data *d)
{
	ft_strdel(line);
	ft_exit(room, NULL, *d);
}
