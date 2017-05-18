/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:49:45 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/05/15 16:49:45 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	read_input(t_read *r)
{
	r->line = NULL;
}

int		main(void)
{
	// char		*line;
	t_read		*r;

	if (!(r = (t_read *)ft_memalloc(sizeof(t_read))))
		return (1);
	read_input(r);
	return (0);
}
