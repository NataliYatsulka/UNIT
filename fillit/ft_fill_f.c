/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:55:24 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:55:25 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_fill_f(t_list *list, char **map, int x, int y)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (x + list->x[i] < *(list->map_size) && y + list->y[i] >= 0 &&
			y + list->y[i] < *(list->map_size) &&
			map[x + list->x[i]][y + list->y[i]] == '.')
			map[x + list->x[i]][y + list->y[i]] = list->letter;
		else
			return (0);
	}
	return (1);
}
