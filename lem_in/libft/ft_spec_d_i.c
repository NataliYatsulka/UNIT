/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:06:25 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/21 21:06:26 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_write_number_d_i(t_flist *list, intmax_t number, int len_arg)
{
	if (len_arg)
		ft_put_nbr(number);
	if (g_width > -1)
	{
		if (list->m == 1 && ((list->zo && g_pres >= 0) || list->zo == 0))
		{
			g_width = g_width - ((g_pres > len_arg) ? g_pres : len_arg);
			ft_put_len_space(g_width, ' ');
		}
	}
	if (number == 0 && g_pres)
	{
		ft_strdel(&(list->res));
		list->res = ft_strnew(1);
	}
}

void		ft_sign(t_flist *list, intmax_t number, int len_arg, int pres)
{
	if (list->s || list->p || number < 0)
	{
		if (number < 0)
			ft_put_len_space(1, '-');
		else if (list->p && number >= 0)
			ft_put_len_space(1, '+');
		else if (list->s && number >= 0)
			ft_put_len_space(1, ' ');
	}
	if (pres >= 0 || (pres < 0 && list->zo && g_width))
	{
		if (pres > len_arg)
		{
			ft_put_len_space(pres - len_arg, '0');
			pres = len_arg;
		}
		else if (g_pres < 0 && g_width > len_arg)
		{
			ft_put_len_space(g_width - len_arg, '0');
			g_width = len_arg;
		}
	}
}

intmax_t	ft_spec_d(va_list *ap)
{
	intmax_t	number;

	number = va_arg(*ap, intmax_t);
	number = (long int)number;
	return (number);
}

void		ft_spec_d_i(t_flist *list, va_list *ap)
{
	intmax_t	number;
	int			len_arg;
	int			pres;
	int			sign;

	pres = g_pres;
	number = (g_sr != 'D' ? ft_signed_size(list, ap) : ft_spec_d(ap));
	sign = ((number < 0 || (number >= 0 && (list->p || list->s))) ? 1 : 0);
	ft_strdel(&(list->res));
	list->res = ft_itoa_base(number, 10);
	len_arg = (number == 0 && g_pres == 0) ? 0 : (int)ft_strlen(list->res);
	if (sign > 0)
		g_width--;
	if (g_width > -1)
	{
		if (list->m == 0 && ((list->zo && g_pres >= 0) || list->zo == 0))
		{
			g_width = g_width - ((g_pres > len_arg) ? g_pres : len_arg);
			ft_put_len_space(g_width, ' ');
		}
	}
	ft_sign(list, number, len_arg, pres);
	ft_write_number_d_i(list, number, len_arg);
	free(list->res);
}
