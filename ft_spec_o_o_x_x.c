/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_o_o_x_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:06:36 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/21 21:06:37 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_sign_o(t_flist *list, int len_arg, int pres, uintmax_t number)
{
	if (list->hs && (number != 0 || (number == 0 && g_pres == 0)))
	{
		ft_put_len_space(1, '0');
		if (pres > 0)
			pres--;
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

void	ft_write_number_o(t_flist *list, int len_arg, uintmax_t number)
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

void	ft_spec_o_o_x_x(t_flist *list, va_list *ap)
{
	uintmax_t	number;
	int			len_arg;

	number = (g_sr != 'O' ? ft_unsigned_size(list, ap) : ft_spec_o(ap));
	ft_strdel(&(list->res));
	list->res = ft_uitoa_base(number, 8);
	len_arg = (number == 0 && g_pres == 0) ? 0 : (int)ft_strlen(list->res);
	if (g_sr == 'o' || g_sr == 'O')
	{
		if (list->hs && g_pres <= len_arg && number != 0)
			g_width--;
		if (g_width > -1)
		{
			if (list->m == 0 && ((list->zo && g_pres >= 0) || list->zo == 0))
			{
				g_width = g_width - ((g_pres > len_arg) ? g_pres : len_arg);
				ft_put_len_space(g_width, ' ');
			}
		}
		ft_sign_o(list, len_arg, g_pres, number);
		ft_write_number_o(list, len_arg, number);
	}
	free(list->res);
}
