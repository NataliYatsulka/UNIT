/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:55:44 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:55:45 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	**ft_fill_d(t_list *list, char **map)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (++i < *(list->map_size))
	{
		j = *(list->map_size);
		if (!(map[i] = (char *)malloc((*(list->map_size) + 1) * sizeof(char))))
			ft_error();
		tmp = map[i];
		while (j--)
			*tmp++ = '.';
		map[i][*(list->map_size)] = '\0';
	}
	return (map);
}
