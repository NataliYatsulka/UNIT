/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_del_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:55:13 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:55:13 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_fill_del_f(t_list *l, char **map, int x, int y)
{
	int		i;

	i = -1;
	while (++i < 4)
		if (x + l->x[i] < *(l->map_size) && y + l->y[i] >= 0 &&
			y + l->y[i] < *(l->map_size) &&
			map[x + l->x[i]][y + l->y[i]] == l->letter)
			map[x + l->x[i]][y + l->y[i]] = '.';
}
