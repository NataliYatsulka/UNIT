/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:56:00 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:56:02 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_coord(t_list *list)
{
	char	**p;
	int		i;
	int		j;
	int		k;
	t_list	*tmp;

	tmp = list;
	while (list)
	{
		k = 0;
		i = -1;
		if ((p = ft_strsplit(list->str, '\n')) != NULL)
			while (++i < 4)
			{
				j = -1;
				while (++j < 4)
					if (p[i][j] == '#')
					{
						list->x[k] = i;
						list->y[k++] = j;
					}
			}
		list = list->next;
	}
	ft_move(tmp);
}
