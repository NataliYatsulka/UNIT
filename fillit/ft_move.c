/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:56:12 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:56:12 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_move(t_list *list)
{
	int		k;
	int		m;
	int		i;
	int		j;

	ft_letter(list);
	while (list)
	{
		i = -1;
		j = -1;
		k = list->x[0];
		m = list->y[0];
		while (++i < 4)
			list->x[i] -= k;
		while (++j < 4)
			list->y[j] -= m;
		list = list->next;
	}
}
