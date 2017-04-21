/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:05:44 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/21 21:05:45 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_rest_r(t_flist *list, int len_arg)
{
	if (list->m == 0 && g_width > 0)
	{
		if (list->zo)
			ft_put_len_space(g_width - len_arg, '0');
		else
			ft_put_len_space(g_width - len_arg, ' ');
	}
}

void	ft_rest(t_flist *list)
{
	int		len_arg;
	int		j;
	int		i;

	i = 0;
	len_arg = 1;
	ft_strdel(&(list->res));
	list->res = ft_strnew(1);
	list->res[0] = g_sr;
	j = len_arg;
	ft_rest_r(list, len_arg);
	if (list->res[0])
	{
		while (j && list->res[i])
		{
			ft_put_count_char(list->res[i]);
			j--;
			i++;
		}
	}
	if (list->m == 1 && g_width > 0)
		ft_put_len_space(g_width - len_arg, ' ');
	ft_strdel(&(list->res));
}
