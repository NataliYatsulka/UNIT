/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_name_room.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:29:01 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/06/27 18:29:01 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_not_links(char *line)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (line[++i])
	{
		if (line[i] == ' ')
			count++;
	}
	if (count == 2)
		return (1);
	return (0);
}

void	create_name_room(t_output *otp)
{
	t_room	*tmp;
	int		num;

	num = 0;
	tmp = otp->room;
	if (tmp)
	{
		while (tmp->next)
		{
			num++;
			tmp = tmp->next;
		}
		if (!(tmp->next = (t_room *)ft_memalloc(sizeof(t_room))))
			return ;
		tmp->next->numb = num + 1;
	}
	else
		otp->room = (t_room *)ft_memalloc(sizeof(t_room));
}
