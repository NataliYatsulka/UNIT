/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 18:01:47 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 18:01:48 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_rec(t_list *l, char **m, int x, int y)
{
	if (ft_fill_f(l, m, x, y) == 1)
	{
		if (l->next)
		{
			if (!ft_srch_coor(l->next, m, 0, 0))
			{
				ft_fill_del_f(l, m, x, y);
				if (y < *(l->map_size))
					ft_srch_coor(l, m, x, ++y);
				else
					((x < *(l->map_size)) ? ft_srch_coor(l, m, ++x, 0) : 0);
			}
		}
		else
			ft_print_map_exit(l, m);
	}
	else
	{
		ft_fill_del_f(l, m, x, y);
		if (y < *(l->map_size))
			ft_srch_coor(l, m, x, ++y);
		else
			((x < *(l->map_size)) ? ft_srch_coor(l, m, ++x, 0) : 0);
	}
}
