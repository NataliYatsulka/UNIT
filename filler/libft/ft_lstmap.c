/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:32:21 by nyatsulk          #+#    #+#             */
/*   Updated: 2016/12/05 21:32:21 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*temp;

	if (!lst)
		return (NULL);
	newlist = f(lst);
	temp = newlist;
	while ((lst = lst->next))
	{
		temp->next = f(lst);
		temp = temp->next;
	}
	return (newlist);
}
