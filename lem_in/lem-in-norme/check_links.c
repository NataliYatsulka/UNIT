/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:28:51 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/06/27 18:28:51 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	find_same_name_room(t_output *otp)
{
	t_room	*ptr;
	t_room	*tmp;

	ptr = otp->room;
	while (ptr)
	{
		tmp = ptr->next;
		while (tmp)
		{
			if (ft_strcmp(tmp->name, ptr->name) == 0)
				ft_error("same room name\n");
			tmp = tmp->next;
		}
		if (ptr->next)
			ptr = ptr->next;
		else
			break ;
	}
}

int		check_links(char *line)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (line[++i])
	{
		if (line[i] == '-')
			count++;
	}
	if (count == 1)
		return (1);
	return (0);
}
