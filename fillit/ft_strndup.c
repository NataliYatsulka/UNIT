/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:01:56 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 17:01:57 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strndup(const char *s1, int n)
{
	int		i;
	char	*temp;

	i = 0;
	if ((temp = (char *)malloc((n + 1) * sizeof(char))) == NULL)
		return (0);
	if (s1 == NULL)
		return (NULL);
	while (s1[i] && n--)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
