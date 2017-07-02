/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:54:27 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:54:28 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	**ft_create_map(t_list *list, int map_size)
{
	char	**map;
	int		i;

	i = -1;
	if (!(map = (char **)malloc(map_size * sizeof(char *))))
		exit(1);
	while (++i < map_size)
	{
		map[i] = (char *)malloc((map_size + 1) * sizeof(char));
		if (!map[i])
			exit(1);
		map[i][map_size] = '\0';
	}
	return (ft_fill_d(list, map));
}
