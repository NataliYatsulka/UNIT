/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_for_two_mas.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:53:29 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/05/03 19:53:31 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	malloc_for_two_mas(char **s, int x, int y)//libft plus
{
	int		i;

	i = -1;
	if (!(s = (char **)ft_memalloc((y + 1) * sizeof(char *))))// y+1????
		return ;
	while (++i < x)
	{
		s[i] = ft_strnew(y);
		if (!s[i])
			return ;
	}
}
