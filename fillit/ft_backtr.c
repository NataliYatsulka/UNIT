/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:53:59 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:53:59 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_backtr(t_list *list)
{
	int		x;
	int		y;
	char	**map;

	*(list->map_size) = ft_map_size(list);
	while (*(list->map_size) < 14)
	{
		x = 0;
		map = ft_create_map(list, *(list->map_size));
		while (x < *(list->map_size))
		{
			y = 0;
			while (y < *(list->map_size))
			{
				ft_del_map(map, *(list->map_size));
				map = ft_create_map(list, *(list->map_size));
				ft_srch_coor(list, map, x, y);
				y++;
			}
			x++;
		}
		ft_del_map(map, *(list->map_size));
		(*(list->map_size))++;
	}
}
