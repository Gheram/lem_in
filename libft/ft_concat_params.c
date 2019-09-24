/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:12:38 by ghtouman          #+#    #+#             */
/*   Updated: 2018/04/12 11:15:36 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_concat_params(int argc, char **argv)
{
	char	*str;
	int		i;
	int		size;

	i = 1;
	size = 0;
	while (i < argc)
		size += (ft_strlen(argv[i++]) + 1);
	str = (char*)malloc(sizeof(*str) * (size));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		ft_strcat(str, argv[i]);
		if (i != argc - 1)
			ft_strcat(str, "\n");
	}
	str[size] = '\0';
	return (str);
}
