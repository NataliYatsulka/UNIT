/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:03:29 by nyatsulk          #+#    #+#             */
/*   Updated: 2016/12/06 19:52:39 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				res;
	unsigned int	i;

	i = 0;
	res = 0;
	while (s1[i] && !(res) && i < (unsigned int)n)
	{
		res = (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (!res && i != n)
		res = (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (res);
}
