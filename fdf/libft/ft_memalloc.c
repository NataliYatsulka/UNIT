/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:19:31 by nyatsulk          #+#    #+#             */
/*   Updated: 2016/11/29 14:32:12 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	if ((s = malloc(size)) == NULL)
		return (NULL);
	while (i < size)
		s[i++] = '\0';
	return (s);
}
