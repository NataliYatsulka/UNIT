/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetriminos_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:59:10 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:59:10 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_check_tetriminos_2(char *s)
{
	int		d;
	int		h;
	int		n;

	d = ft_check_d(s);
	d = d / 12;
	h = ft_check_h(s);
	h = h / 4;
	n = ft_check_n(s);
	n = (n + 1) / 5;
	if (d != ft_check_3(s) || h != ft_check_3(s) || n != ft_check_3(s))
		ft_error();
	else
		return (1);
	return (0);
}
