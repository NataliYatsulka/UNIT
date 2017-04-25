/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:37:54 by nyatsulk          #+#    #+#             */
/*   Updated: 2016/12/01 13:37:55 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*p;
	int			len;
	int			neg;
	long int	k;

	neg = 0;
	k = n;
	len = ft_nb_itoa(n);
	if ((p = malloc(len + 1)) == NULL)
		return (NULL);
	p[len] = '\0';
	if (k < 0)
	{
		neg = 1;
		k = -k;
	}
	while (len)
	{
		p[len - 1] = '0' + k % 10;
		k /= 10;
		len--;
	}
	if (neg == 1)
		p[0] = '-';
	return (p);
}
