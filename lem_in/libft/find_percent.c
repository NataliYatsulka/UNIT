/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:02:42 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/21 21:02:49 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_zero(t_flist *list, int i)
{
	if ((list->str = (char *)malloc((i + 1) * sizeof(char))) != NULL)
		ft_bzero(list->str, (size_t)(i + 1));
	list->m = 0;
	list->p = 0;
	list->s = 0;
	list->hs = 0;
	list->zo = 0;
	list->w = 0;
	list->d = 0;
	list->prs = 0;
	list->res = NULL;
	list->h = 0;
	list->hh = 0;
	list->l = 0;
	list->ll = 0;
	list->j = 0;
	list->z = 0;
	g_pres = -1;
}

char	*ft_strnchar(char *start, char *spec)
{
	int		i;
	int		k;

	i = 0;
	if (start[i] && start[i + 1])
		i++;
	while (start[i])
	{
		if (start[i] != '\0')
		{
			k = 0;
			while (spec[k] && start[i] != spec[k])
				k++;
			if (start[i] == spec[k])
			{
				g_sr = spec[k];
				break ;
			}
			i++;
		}
		else
			break ;
	}
	return (start + i);
}

char	*ft_strnchar_for_else_flag(char *start, char *spec)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (start[i + 1])
	{
		i++;
		while (start[i])
		{
			if ((tmp = ft_strchr(spec, start[i])) != NULL)
				i++;
			else
			{
				g_sr = start[i];
				return (start + i);
			}
		}
	}
	else
		g_sr = '\0';
	return (start + i);
}

void	ft_choose(t_flist *list, va_list *ap)
{
	if (g_sr == 'd' || g_sr == 'i' || g_sr == 'D')
		ft_spec_d_i(list, ap);
	else if (g_sr == 'u' || g_sr == 'U')
		ft_spec_u_u(list, ap);
	else if (g_sr == 'o' || g_sr == 'O')
		ft_spec_o_o_x_x(list, ap);
	else if (g_sr == 'x' || g_sr == 'X' || g_sr == 'p')
		ft_spec_x_x(list, ap);
	else if (g_sr == 's' || g_sr == 'S')
		ft_spec_s_s(list, ap);
	else if (g_sr == 'c' || g_sr == 'C')
		ft_spec_c_c(list, ap);
	else
		ft_rest(list);
	ft_delete_g_varib(list);
}

int		find_percent(char *tmp)
{
	int		i;

	i = 0;
	if (tmp[i] && tmp[i + 1])
		i++;
	while (tmp[i])
	{
		if (tmp[i] == '%')
			return (1);
		i++;
	}
	return (-1);
}
