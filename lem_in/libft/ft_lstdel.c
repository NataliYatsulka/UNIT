/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:27:10 by nyatsulk          #+#    #+#             */
/*   Updated: 2016/12/05 21:27:10 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*listnew;

	list = *alst;
	while (list)
	{
		listnew = list->next;
		del(list->content, list->content_size);
		free(list);
		list = listnew;
	}
	*alst = NULL;
}
