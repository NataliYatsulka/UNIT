/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:20:43 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/21 20:20:43 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_find_last_g_sr(char *tmp, char *s1, char *s2)
{
	int		i;

	i = 0;
	while (ft_strchr(s1, tmp[i]))
		i++;
	if (!ft_strchr(s2, tmp[i]))
	{
		g_sr = tmp[i];
		return ;
	}
	else
		i++;
	g_sr = '\0';
}

void	ft_jdi(char *tmp, int i, va_list *ap)
{
	t_flist		*list;

	if (g_sr == '\0')
		return ;
	else
	{
		if ((list = (t_flist *)malloc(sizeof(t_flist))) == NULL)
			return ;
		ft_list_zero(list, i);
		ft_init_flags(list, tmp + 1, i);
		ft_choose(list, ap);
	}
	ft_strdel(&(list->str));
	free(list);
}

void	ft_just_do_it(char **start, va_list *ap)
{
	char		*tmp;
	int			i;
	char		*xx;

	tmp = *start;
	xx = ft_strnchar_for_else_flag(tmp, "-+ .#0123456789lhzjsSpdDioOuUxXcC");
	*start = ft_strnchar(*start, "%sSpdDioOuUxXcC");
	if (xx < *start)
	{
		g_sr = '\0';
		*start = ft_strnchar(*start, "%");
	}
	if (g_sr == '\0' || g_sr == '%')
		*start = ft_strnchar_for_else_flag(tmp, "-+ .#0123456789lhzj");
	i = *start - tmp;
	ft_jdi(tmp, i, ap);
}

void	ft_realise(const char *format, va_list *ap)
{
	char	*start;
	char	*end;

	start = (char *)format;
	end = (char *)format;
	while (*end != '\0')
	{
		if (*end == '%')
		{
			ft_putnstr(start, end - start);
			ft_just_do_it(&end, ap);
			start = end + 1;
		}
		else if (*end != '\0')
			;
		end++;
	}
	ft_putnstr(start, end - start);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;

	g_res = 0;
	va_start(ap, format);
	ft_realise(format, &ap);
	va_end(ap);
	return (g_res);
}
