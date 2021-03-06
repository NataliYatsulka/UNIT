/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:54:11 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:54:11 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_del_map(char **map, int map_size)
{
	int		i;

	i = -1;
	while (++i < map_size)
		free(map[i]);
	free(map);
}
