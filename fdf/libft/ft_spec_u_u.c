/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_u_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:06:57 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/21 21:06:58 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_spec_o(va_list *ap)
{
	uintmax_t	number;
	void		*arg;

	arg = va_arg(*ap, void *);
	number = (unsigned long int)arg;
	return (number);
}

void		ft_write_number_u(t_flist *list, uintmax_t number, int len_arg)
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
	if (number == 0 && g_pres)
	{
		ft_strdel(&(list->res));
		list->res = ft_strnew(1);
	}
}

void		ft_sign_u(t_flist *list, int len_arg, int pres)
{
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

void		ft_spec_u_u(t_flist *list, va_list *ap)
{
	uintmax_t	number;
	int			len_arg;
	int			pres;

	pres = g_pres;
	if (g_sr == 'U' || (g_sr == 'u' && list->l))
		number = ft_spec_o(ap);
	else
		number = ft_unsigned_size(list, ap);
	ft_strdel(&(list->res));
	list->res = ft_uitoa_base(number, 10);
	len_arg = (number == 0 && g_pres == 0) ? 0 : (int)ft_strlen(list->res);
	if (g_width > -1)
	{
		if (list->m == 0 && ((list->zo && g_pres >= 0) || list->zo == 0))
		{
			g_width = g_width - ((g_pres > len_arg) ? g_pres : len_arg);
			ft_put_len_space(g_width, ' ');
		}
	}
	ft_sign_u(list, len_arg, pres);
	ft_write_number_u(list, number, len_arg);
	free(list->res);
}
