/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:00:50 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 17:00:51 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_check_h(char *s)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (s[++i])
		if (s[i] == '#')
			j++;
	return (j);
}
