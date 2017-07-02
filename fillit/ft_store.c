/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:01:49 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 17:01:49 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_list	*ft_store(char *s)
{
	t_list	*blok;
	t_list	*head;
	int		i;
	int		n;

	i = 0;
	n = ft_check_3(s);
	if (ft_check_tetriminos_1(s) < 1)
		ft_error();
	if (!(blok = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	head = blok;
	while (n-- > 0)
	{
		blok->str = ft_strndup(&s[i], 20);
		((n && s[i + 20] != '\n') ? (ft_error()) : 0);
		((ft_valid(blok->str) < 1) ? (ft_error()) : 0);
		i = i + 21;
		if (n == 0)
			break ;
		blok->next = (t_list*)malloc(sizeof(t_list));
		blok = blok->next;
	}
	blok->next = NULL;
	return (head);
}
