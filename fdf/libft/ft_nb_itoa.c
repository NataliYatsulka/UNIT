/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:48:23 by nyatsulk          #+#    #+#             */
/*   Updated: 2016/12/01 15:48:24 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nb_itoa(int n)
{
	int		counter;

	counter = 0;
	if (n == 0)
		counter++;
	if (n < 0)
	{
		counter++;
	}
	while (n)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}
