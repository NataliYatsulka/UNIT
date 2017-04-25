/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:33:08 by nyatsulk          #+#    #+#             */
/*   Updated: 2016/11/28 16:09:11 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		counter;

	i = 0;
	j = 0;
	counter = 0;
	if (little[0] == '\0')
		return ((char *)&big[0]);
	while (big[i])
	{
		counter = i;
		j = 0;
		while (little[j] == big[counter])
		{
			counter++;
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
