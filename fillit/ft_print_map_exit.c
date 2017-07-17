/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 18:02:01 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 18:02:01 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_print_map_exit(t_list *list, char **map)
{
	ft_print_map(list, map);
	exit(0);
}