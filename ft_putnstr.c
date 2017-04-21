/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:05:34 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/21 21:05:34 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	f(intmax_t value, int base, char *s, int *i)
{
	char	*tmp;

	if (g_sr == 'X')
		tmp = "0123456789ABCDEF";
	else
		tmp = "0123456789abcdef";
	if (value <= -base || value >= base)
		f(value / base, base, s, i);
	s[(*i)++] = tmp[(value % base) < 0 ? -(value % base) : (value % base)];
}

char	*ft_itoa_base(intmax_t value, int base)
{
	int		i;
	char	*s;

	i = -1;
	if (base < 2 || base > 16 || !(s = (char *)malloc(66)))
		return (0);
	if (base == 10 && value < 0)
		s[++i] = '-';
	else
		i++;
	f(value, base, s, &i);
	s[i] = '\0';
	return (s);
}

void	fu(uintmax_t value, int base, char *s, int *i)
{
	char	*tmp;

	if (g_sr == 'X')
		tmp = "0123456789ABCDEF";
	else
		tmp = "0123456789abcdef";
	if (value >= (uintmax_t)base)
		fu(value / base, base, s, i);
	s[(*i)++] = tmp[(value % base) ? (value % base) : (value % base)];
}

char	*ft_uitoa_base(uintmax_t value, int base)
{
	int		i;
	char	*s;

	i = 0;
	if (base < 2 || base > 16 || !(s = (char *)malloc(66)))
		return (0);
	fu(value, base, s, &i);
	s[i] = '\0';
	return (s);
}

void	ft_putnstr(char const *s, int len)
{
	int i;

	i = -1;
	if (s == '\0')
		return ;
	while (s[++i] && len > 0)
	{
		ft_put_count_char(s[i]);
		len--;
	}
}
