/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:58:46 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:58:47 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_valid(char *s)
{
	int		i;
	int		counter;

	i = -1;
	counter = 0;
	while (s[++i])
	{
		if (s[i] == '#' && i < 20)
		{
			if (i < 19)
				counter += (s[i + 1] == '#') ? 1 : 0;
			if (i > 0)
				counter += (s[i - 1] == '#') ? 1 : 0;
			if (i < 14)
				counter += (s[i + 5] == '#') ? 1 : 0;
			if (i > 4)
				counter += (s[i - 5] == '#') ? 1 : 0;
		}
	}
	if (counter < 6)
		ft_error();
	return (1);
}
