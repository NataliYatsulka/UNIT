/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:05:16 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/21 21:05:17 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_count_char(char c)
{
	write(1, &c, 1);
	g_res++;
}

void	ft_put_count_str(char const *s)
{
	if (s)
	{
		while (*s)
		{
			ft_put_count_char(*s);
			s++;
		}
	}
}

void	ft_put_unbr(uintmax_t nb)
{
	if (nb > 9)
	{
		ft_put_unbr(nb / 10);
		ft_put_unbr(nb % 10);
	}
	else
		ft_put_count_char(nb + '0');
}

void	ft_put_nbr(intmax_t nb)
{
	uintmax_t		numb;

	numb = 0;
	if (nb < 0)
		numb = (-1) * nb;
	else if (nb < 0)
		nb = (-1) * nb;
	if (nb > 9)
	{
		ft_put_nbr(nb / 10);
		ft_put_nbr(nb % 10);
	}
	else if (nb <= 9 && numb == 0)
		ft_put_count_char(nb + '0');
	else
		ft_put_unbr(numb);
}
