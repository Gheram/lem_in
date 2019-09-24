/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:14:18 by ghtouman          #+#    #+#             */
/*   Updated: 2019/08/10 12:51:02 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			add_buf(t_buf **pad)
{
	t_buf		*elem;
	t_buf		*tmp;

	if (!(elem = (t_buf*)malloc(sizeof(t_buf))))
		exit(1);
	elem->len = 0;
	elem->next = NULL;
	elem->sep = NULL;
	if (*pad == NULL)
	{
		if (!(tmp = (t_buf*)malloc(sizeof(t_buf))))
			exit(1);
		tmp->len = 0;
		tmp->next = NULL;
		tmp->sep = NULL;
		*pad = tmp;
	}
	else
		tmp = (*pad)->last;
	tmp->next = elem;
	(*pad)->last = elem;
}

t_buf			*lst_buf(char *line, t_buf *pad)
{
	int			i;

	i = 0;
	if (pad == NULL)
		add_buf(&pad);
	while (line[i])
	{
		if ((pad->last->len + ft_strlen(line)) >= BUF_SIZE)
			add_buf(&pad);
		pad->last->buf[pad->last->len++] = line[i++];
	}
	pad->last->buf[pad->last->len++] = '\n';
	return (pad);
}

static void		write_in_buf(t_sol **ant, t_buf *pad, int i, int n)
{
	char		*a_num;
	int			j;

	j = 0;
	(pad->last->len + 1) >= BUF_SIZE ? add_buf(&pad) : pad;
	pad->last->buf[pad->last->len++] = 'L';
	a_num = ft_itoa(i + 1);
	pad->last->len + ft_strlen(a_num) >= BUF_SIZE ? add_buf(&pad) : pad;
	while (a_num[j])
		pad->last->buf[pad->last->len++] = a_num[j++];
	(pad->last->len + 1) >= BUF_SIZE ? add_buf(&pad) : pad;
	pad->last->buf[pad->last->len++] = '-';
	j = 0;
	pad->last->len + ft_strlen(ant[i]->name) >= BUF_SIZE ? add_buf(&pad) : pad;
	while (ant[i]->name[j])
		pad->last->buf[pad->last->len++] = ant[i]->name[j++];
	(pad->last->len + 1) >= BUF_SIZE ? add_buf(&pad) : pad;
	if (i + 1 != n)
		pad->last->buf[pad->last->len++] = ' ';
	free(a_num);
}

void			fill_buf(t_sol **ant, int n, t_data *d, t_buf *pad)
{
	int			i;

	i = 0;
	while (i < n)
	{
		if (ant[i])
			write_in_buf(ant, pad, i, n);
		i++;
	}
	(pad->last->len + 1) >= BUF_SIZE ? add_buf(&pad) : pad;
	if (d->start_end == 0)
		pad->last->buf[pad->last->len++] = '\n';
	if (d->start_end == 1 && i != d->nb_ant)
		pad->last->buf[pad->last->len++] = ' ';
}
