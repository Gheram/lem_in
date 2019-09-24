/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:39:37 by ghtouman          #+#    #+#             */
/*   Updated: 2019/08/10 12:52:48 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_bool			find_dash(char *str)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != ' ')
		if (str[i++] == '-')
			return (true);
	return (false);
}

int				check_ascii(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] > 127 || line[i] < 0)
			return (-1);
		i++;
	}
	return (0);
}

t_way			**init_get_way(t_way **tab_way, t_data *d)
{
	int			count;

	count = d->nb_room;
	if (!(tab_way = (t_way**)malloc(sizeof(t_way*) * (d->nb_room))))
		exit(1);
	while (count--)
		tab_way[count] = NULL;
	return (tab_way);
}

static t_bool	is_coord(char *str, int i)
{
	int			check;

	check = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
			check++;
		i++;
	}
	if (check == 2)
		return (false);
	return (true);
}

char			*strdup_lim(char *str, t_data *d, t_room **elem, t_room **room)
{
	int			i;
	char		*ret;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	(*elem)->len_name = i;
	i++;
	if (!(ret = (char*)malloc(sizeof(char) * i)))
		exit(1);
	i = 0;
	if (str[0] == 'L' || is_coord(str, i))
	{
		free(*elem);
		ft_strdel(&str);
		ft_strdel(&ret);
		ft_exit(room, NULL, *d);
	}
	while (i < (*elem)->len_name)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i++] = '\0';
	return (ret);
}
