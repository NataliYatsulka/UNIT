/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:29:26 by nyatsulk          #+#    #+#             */
/*   Updated: 2016/11/28 16:06:39 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned long int		i;

	i = 0;
	while (s[i])
		i++;
	while (i > 0 && (s[i] != (char)c))
		i--;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
