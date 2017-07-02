/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:53:39 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:53:39 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		main(int ac, char **av)
{
	t_list	*list;
	t_list	*head;
	int		*ptr;

	if (ac != 2)
		usage(av[0]);
	list = ft_store(ft_read_file(av[1]));
	ptr = (int *)malloc(sizeof(int));
	head = list;
	while (head)
	{
		head->map_size = ptr;
		head = head->next;
	}
	ft_coord(list);
	ft_backtr(list);
	return (0);
}
