/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srch_coor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:54:37 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:54:37 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	**ft_srch_coor(t_list *list, char **map, int x, int y)
{
	int		z;

	z = x;
	x = ft_x(map, *(list->map_size), z, y);
	y = ft_y(map, *(list->map_size), z, y);
	if (x != *(list->map_size) && y != *(list->map_size))
		ft_rec(list, map, x, y);
	return (0);
}
