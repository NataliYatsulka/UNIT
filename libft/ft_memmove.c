/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:05:21 by nyatsulk          #+#    #+#             */
/*   Updated: 2016/11/28 19:22:55 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;
	char	*b;

	a = (char *)dst;
	b = (char *)src;
	if (len > 0)
	{
		if (b < a)
		{
			while (len > 0)
			{
				len--;
				*(a + len) = *(b + len);
			}
		}
		else
			ft_memcpy(a, b, len);
	}
	return (a);
}
