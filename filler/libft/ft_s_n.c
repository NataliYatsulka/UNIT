/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:05:55 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/21 21:05:56 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	wsrt(t_flist *list, wchar_t *arg)
{
	char	*s1;
	char	*s2;

	if (!list->res)
		list->res = ft_conw_char(*arg);
	else
	{
		s1 = ft_strdup(list->res);
		ft_strdel(&list->res);
		s2 = ft_conw_char(*arg);
		list->res = ft_strjoin(s1, s2);
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
}

void	conv_wstr(t_flist *list, wchar_t *arg)
{
	int		i;

	i = 0;
	if (!arg)
		list->res = ft_strdup("(null)");
	else if (g_pres >= 0)
	{
		while (*arg && ((i += leng_wchar(*arg)) <= g_pres))
		{
			wsrt(list, arg);
			arg++;
		}
	}
	else
	{
		while (*arg)
		{
			wsrt(list, arg);
			arg++;
		}
	}
	if (!list->res)
		list->res = ft_strdup("");
}

void	ft_s_n(t_flist *list)
{
	if (list->zo && list->m)
		list->zo = 0;
	if (list->p && list->s)
		list->s = 0;
}
