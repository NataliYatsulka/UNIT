/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_s_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:06:46 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/21 21:06:47 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sign_s(t_flist *list, int len_arg)
{
	if (g_width > -1)
	{
		if (list->m == 0)
		{
			if (g_pres >= 0)
				g_width = g_width - ((g_pres > len_arg) ? len_arg : g_pres);
			else if (g_width > g_pres || g_width > len_arg)
				g_width = g_width - ((g_pres >= 0) ? g_pres : len_arg);
			if (list->zo)
				ft_put_len_space(g_width, '0');
			else
				ft_put_len_space(g_width, ' ');
		}
	}
}

void	ft_wns(t_flist *list, int i, int k)
{
	while (list->res[i])
	{
		ft_put_count_char(list->res[i]);
		i++;
		k++;
	}
}

void	ft_write_number_s(t_flist *list, int len_arg, int pres, int k)
{
	int		i;

	i = 0;
	if (len_arg && g_pres >= 0)
	{
		while (pres > 0 && list->res[i])
		{
			ft_put_count_char(list->res[i]);
			pres--;
			i++;
		}
	}
	else
		ft_wns(list, i, k);
	if (g_width > -1 && list->m == 1)
	{
		if (g_pres >= 0)
			g_width = g_width - ((g_pres > len_arg) ? len_arg : g_pres);
		else if (g_width > g_pres || g_width > len_arg)
			g_width = g_width - ((g_pres >= 0) ? g_pres : len_arg);
		ft_put_len_space(g_width, ' ');
	}
}

void	ft_sp_s(t_flist *list, int len_arg, int pres, int k)
{
	if (*list->res == '\0')
	{
		if (list->zo)
			ft_put_len_space(g_width, '0');
		else
			ft_put_len_space(g_width, ' ');
	}
	else
	{
		ft_sign_s(list, len_arg);
		ft_write_number_s(list, len_arg, pres, k);
	}
	ft_strdel(&(list->res));
}

void	ft_spec_s_s(t_flist *list, va_list *ap)
{
	void	*arg;
	int		len_arg;
	int		pres;
	int		k;

	k = 0;
	pres = g_pres;
	arg = va_arg(*ap, void *);
	if (g_sr == 'S' || (g_sr == 's' && list->l == 1))
		conv_wstr(list, (wchar_t *)arg);
	else if ((char *)arg)
		list->res = ft_strdup((char *)arg);
	else
		list->res = ft_strdup("(null)");
	len_arg = (int)ft_strlen(list->res);
	ft_sp_s(list, len_arg, pres, k);
}
