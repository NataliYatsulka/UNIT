/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_len_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:04:59 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/21 21:05:00 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

uintmax_t	ft_unsigned_size(t_flist *list, va_list *ap)
{
	uintmax_t	number;

	number = va_arg(*ap, uintmax_t);
	if (list->j)
		number = (uintmax_t)number;
	else if (list->z)
		number = (size_t)number;
	else if (list->ll)
		number = (unsigned long long int)number;
	else if (list->l)
		number = (unsigned long int)number;
	else if (list->h)
		number = (unsigned short int)number;
	else if (list->hh)
		number = (unsigned char)number;
	else
		number = (unsigned int)number;
	return (number);
}

intmax_t	ft_signed_size(t_flist *list, va_list *ap)
{
	intmax_t	number;

	number = va_arg(*ap, intmax_t);
	if (list->j)
		number = (intmax_t)number;
	else if (list->z)
		number = (size_t)number;
	else if (list->ll)
		number = (long long int)number;
	else if (list->l)
		number = (long int)number;
	else if (list->h)
		number = (signed short int)number;
	else if (list->hh)
		number = (signed char)number;
	else
		number = (int)number;
	return (number);
}

void		ft_put_len_space(int len, char s)
{
	while (len > 0)
	{
		write(1, &s, 1);
		len--;
		g_res++;
	}
}
