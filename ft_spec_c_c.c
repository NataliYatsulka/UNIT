/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_c_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:06:14 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/21 21:06:14 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		leng_wchar(wchar_t arg)
{
	if (arg <= 127)
		return (1);
	else if (arg <= 2047)
		return (2);
	else if (arg <= 65535)
		return (3);
	else if (arg <= 2097151)
		return (4);
	return (0);
}

char	*ft_conw_char(wchar_t arg)
{
	int		i;
	char	*s;

	i = leng_wchar(arg);
	s = ft_strnew(i);
	if (i == 1)
		s[0] = (char)arg;
	else
		s[0] = (arg >> (6 * (i - 1))) | (240 << (4 - i));
	while (--i > 0)
	{
		s[i] = (arg & 63) | 128;
		arg = arg >> 6;
	}
	return (s);
}

void	ft_write_number_c(t_flist *list, int len_arg, int j, int i)
{
	if (list->m == 0 && g_width > 0)
	{
		if (list->zo)
			ft_put_len_space(g_width - len_arg, '0');
		else
			ft_put_len_space(g_width - len_arg, ' ');
	}
	if (list->res[0] || list->res[0] == 0)
	{
		if (list->res[0] == 0 && (g_sr == 'C' || g_sr == 'c'))
		{
			write(1, "\0", 1);
			g_res++;
		}
		while (j && list->res[i])
		{
			ft_put_count_char(list->res[i]);
			j--;
			i++;
		}
	}
	if (list->m == 1 && g_width > 0)
		ft_put_len_space(g_width - len_arg, ' ');
}

void	ft_spec_c_c(t_flist *list, va_list *ap)
{
	void	*arg;
	int		len_arg;
	int		j;
	int		i;

	i = 0;
	arg = va_arg(*ap, void *);
	len_arg = 1;
	ft_strdel(&(list->res));
	if (g_sr == 'C' || (g_sr == 'c' && list->l == 1))
	{
		list->res = ft_conw_char((wchar_t)arg);
		len_arg = ft_strlen(list->res);
	}
	else
	{
		list->res = ft_strnew(1);
		list->res[0] = (char)arg;
	}
	j = len_arg;
	ft_write_number_c(list, len_arg, j, i);
	ft_strdel(&(list->res));
}
