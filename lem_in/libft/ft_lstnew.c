/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:28:31 by nyatsulk          #+#    #+#             */
/*   Updated: 2016/12/02 11:28:32 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *cont, size_t cont_size)
{
	t_list *lst;

	if ((lst = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (0);
	if (cont == NULL)
	{
		lst->content_size = 0;
		lst->content = NULL;
	}
	else
	{
		if ((lst->content = (void*)malloc(sizeof(cont_size))) == NULL)
			return (0);
		ft_memcpy(lst->content, cont, cont_size);
		lst->content_size = cont_size;
	}
	lst->next = NULL;
	return (lst);
}
