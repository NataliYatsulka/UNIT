/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_x_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:03:14 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/21 21:07:33 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_sign_x(t_flist *list, int len_arg, int pres, uintmax_t number)
{
	if (list->hs && number != 0)
	{
		ft_put_len_space(1, '0');
		if (g_sr == 'x' || g_sr == 'p')
			ft_put_len_space(1, 'x');
		else
			ft_put_len_space(1, 'X');
	}
	if (pres >= 0 || (pres < 0 && list->zo && g_width))
	{
		if (pres > len_arg)
			ft_put_len_space(pres - len_arg, '0');
		else if (g_pres < 0 && g_width > len_arg)
		{
			ft_put_len_space(g_width - len_arg, '0');
			g_width = len_arg;
		}
	}
}

void	ft_write_number_x(t_flist *list, int len_arg, uintmax_t number)
{
	if (number == 0 && g_pres == 0)
		;
	else if (len_arg)
		ft_put_count_str(list->res);
	if (g_width > -1)
	{
		if (list->m == 1 && ((list->zo && g_pres >= 0) || list->zo == 0))
		{
			g_width = g_width - ((g_pres > len_arg) ? g_pres : len_arg);
			ft_put_len_space(g_width, ' ');
		}
	}
}

void	ft_after(t_flist *list, uintmax_t number, int len_arg)
{
	if (list->hs && number != 0)
		g_width = g_width - 2;
	if (g_width > -1)
	{
		if (list->m == 0 && ((list->zo && g_pres >= 0) || list->zo == 0))
		{
			g_width = g_width - ((g_pres > len_arg) ? g_pres : len_arg);
			ft_put_len_space(g_width, ' ');
		}
	}
	ft_sign_x(list, len_arg, g_pres, number);
	ft_write_number_x(list, len_arg, number);
	free(list->res);
}

void	ft_spec_x_x(t_flist *list, va_list *ap)
{
	uintmax_t	number;
	void		*arg;
	int			len_arg;

	number = 1;
	ft_strdel(&(list->res));
	if (g_sr == 'p')
	{
		arg = va_arg(*ap, void *);
		list->res = ft_itoa_base((unsigned long int)arg, 16);
		if (!arg && g_pres == 0)
			len_arg = 0;
		else
			len_arg = (int)ft_strlen(list->res);
		list->hs = 1;
	}
	else
	{
		number = ft_unsigned_size(list, ap);
		list->res = ft_uitoa_base(number, 16);
		len_arg = (int)ft_strlen(list->res);
		if (number == 0 && g_pres == 0)
			len_arg = 0;
	}
	ft_after(list, number, len_arg);
}
