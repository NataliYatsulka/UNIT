/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:22:11 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/06 16:22:11 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#include <limits.h>

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_res++;
}

void	ft_putstr(char const *s)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
}

void	ft_put_unbr(uintmax_t nb)
{
	if (nb > 9)
	{
		ft_put_unbr(nb / 10);
		ft_put_unbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

void	ft_put_nbr(intmax_t nb)
{
	uintmax_t 		numb;

	numb = 0;
	if (nb < 0)
	{
		numb = (-1) * nb;
	}
	else if (nb < 0)
		nb = (-1) * nb;
	if (nb > 9)
	{
		ft_put_nbr(nb / 10);
		ft_put_nbr(nb % 10);
	}
	else if (nb <= 9 && numb == 0)
		ft_putchar(nb + '0');
	else
		ft_put_unbr(numb);
}

char	*ft_strnew(size_t size)
{
	char	*p;
	size_t	i;

	i = -1;
	if ((p = (char *)malloc((size + 1) * (sizeof(char)))) == NULL)
		return (NULL);
	while (++i < size)
		p[i] = 0;
	p[i] = '\0';
	return (p);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while (len && src[i])
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	while (len > 0)
	{
		dst[i] = '\0';
		i++;
		len--;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s && s[i] == '\0' && c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

void	ft_putnstr(char const *s, int len)
{
	int i;

	i = -1;
	if (s == '\0')
		return ;
	while (s[++i] && len > 0)
	{
		ft_putchar(s[i]);
		len--;
	}
}

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

void	ft_strdel(char **as)
{
	if (as == '\0')
		return ;
	free(*as);
	*as = NULL;
}

char	*ft_strdup(const char *s1)
{
	int		i;
	size_t	len;
	char	*temp;

	i = 0;
	len = ft_strlen(s1);
	if ((temp = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (0);
	if (s1 == NULL)
		return (NULL);
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (s1 == '\0' || s2 == '\0')
		return (NULL);
	p = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_strcpy(p, s1);
	ft_strcat(p, s2);
	return (p);
}

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


uintmax_t	ft_unsigned_size(t_flist *list, va_list *ap)
{
	uintmax_t	number;

	number = va_arg(*ap, uintmax_t);
	if (list->j)
		number = (uintmax_t)number;
	else if (list->z)
		number = (size_t)number;
	else if (list->ll)
		number = (unsigned long long int)number;
	else if (list->l)
		number = (unsigned long int)number;
	else if (list->h)
		number = (unsigned short int)number;
	else if (list->hh)
		number = (unsigned char)number;
	else
		number = (unsigned int)number;
	return (number);
}

intmax_t	ft_signed_size(t_flist *list, va_list *ap)
{
	intmax_t	number;

	number = va_arg(*ap, intmax_t);
	if (list->j)
		number = (intmax_t)number;
	else if (list->z)
		number = (size_t)number;
	else if (list->ll)
		number = (long long int)number;
	else if (list->l)
		number = (long int)number;
	else if (list->h)
		number = (signed short int)number;
	else if (list->hh)
		number = (signed char)number;
	else
		number = (int)number;
	return (number);
}

void	ft_put_len_space(int len, char s)
{
	while (len > 0)
	{
		write (1, &s, 1);
		len--;
		g_res++;
	}
}

uintmax_t	ft_spec_O(va_list *ap)
{
	unsigned long int	number;

	number = va_arg(*ap, unsigned long int);
	//number = (unsigned long int)number;
	return (number);
}

void	ft_write_number_u(t_flist *list, uintmax_t number, int len_arg)
{
	if (number == 0 && g_pres == 0)
		;
	else if (len_arg) 
		ft_putstr(list->res);
	if (g_width > -1)
	{
		if (list->m == 1 && ((list->zo && g_pres >= 0) || list->zo == 0))
		{
			g_width = g_width - ((g_pres > len_arg) ? g_pres : len_arg);
			ft_put_len_space(g_width, ' ');
		}
	}
	if (number == 0 && g_pres)
		list->res = ft_strnew(1);
}

void	ft_sign_u(t_flist *list, int len_arg, int pres)
{
	if (pres >= 0 || (pres < 0 && list->zo && g_width))
	{
		if (pres > len_arg)
		{
			ft_put_len_space(pres - len_arg, '0');
			pres = len_arg;
		}
		else if (g_pres < 0 && g_width > len_arg)
		{
			ft_put_len_space(g_width - len_arg, '0');
			g_width = len_arg;
		}
	}
}

void	ft_spec_u_U(t_flist *list, va_list *ap)
{
	uintmax_t	number;
	int			len_arg;
	int			pres;
	int 		sign;

	pres = g_pres;
	number = (g_sr != 'U' ? ft_unsigned_size(list, ap) : ft_spec_O(ap));
	sign = (list->p || list->s) ? 1 : 0;
	list->res = ft_itoa_base(number, 10);
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
		{
			ft_put_len_space(pres - len_arg, '0');
			pres = len_arg;
		}
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
		ft_putstr(list->res);
	if (g_width > -1)
	{
		if (list->m == 1 && ((list->zo && g_pres >= 0) || list->zo == 0))
		{
			g_width = g_width - ((g_pres > len_arg) ? g_pres : len_arg);
			ft_put_len_space(g_width, ' ');
		}
	}
}

void	ft_spec_x_X(t_flist *list, va_list *ap)
{
	uintmax_t	number;
	void		*arg;
	int			len_arg;

	number = 1; // можливо треба виділити в іншу функцію number????
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
		list->res = ft_itoa_base(number, 16);
		len_arg = (int)ft_strlen(list->res);
		if (number == 0 && g_pres == 0)
			len_arg = 0;
	}
	// len_arg = (list->res == 0 && g_pres == 0) ? 0 : (int)ft_strlen(list->res);
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

void	ft_sign_o(t_flist *list, int len_arg, int pres, uintmax_t number)
{
	if (list->hs && number != 0)
	{
		ft_put_len_space(1, '0');
		if (pres > 0)
			pres--;
	}
	if (pres >= 0 || (pres < 0 && list->zo && g_width))
	{
		if (pres > len_arg)
		{
			ft_put_len_space(pres - len_arg, '0');
			pres = len_arg;
		}
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
		ft_putstr(list->res);
	if (g_width > -1)
		{
			if (list->m == 1 && ((list->zo && g_pres >= 0) || list->zo == 0))
			{
				g_width = g_width - ((g_pres > len_arg) ? g_pres : len_arg);
				ft_put_len_space(g_width, ' ');
			}
		}
}

void	ft_spec_o_O_x_X(t_flist *list, va_list *ap)
{
	uintmax_t	number;
	int			len_arg;

	number = (g_sr != 'O' ? ft_unsigned_size(list, ap) : ft_spec_O(ap));
	list->res = ft_itoa_base(number, 8);
	len_arg = (list->res == 0 && g_pres == 0) ? 0 : (int)ft_strlen(list->res);
	if (g_sr == 'o' || g_sr == 'O')
	{
		if (number == 0 && g_pres == 0)
			len_arg = 0;
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
		free(list->res);
	}
}

void	ft_write_number_d_i(t_flist *list, intmax_t number, int len_arg)
{
	if (len_arg)
		ft_put_nbr(number);
	if (g_width > -1)
	{
		if (list->m == 1 && ((list->zo && g_pres >= 0) || list->zo == 0))
		{
			g_width = g_width - ((g_pres > len_arg) ? g_pres : len_arg);
			ft_put_len_space(g_width, ' ');
		}
	}
	if (number == 0 && g_pres)
		list->res = ft_strnew(1);
}

void	ft_sign(t_flist *list, intmax_t number, int len_arg, int pres)
{
	if (list->s || list->p || number < 0)
	{
		if (number < 0)
			ft_put_len_space(1, '-');
		else if (list->p && number >= 0)
			ft_put_len_space(1, '+');
		else if (list->s && number >= 0)
			ft_put_len_space(1, ' ');
	}
	if (pres >= 0|| (pres < 0 && list->zo && g_width))
	{
		if (pres > len_arg)
		{
			ft_put_len_space(pres - len_arg, '0');
			pres = len_arg;
		}
		else if (g_pres < 0 && g_width > len_arg)
		{
			ft_put_len_space(g_width - len_arg, '0');
			g_width = len_arg;
		}
	}
}

intmax_t	ft_spec_D(va_list *ap)
{
	intmax_t	number;

	number = va_arg(*ap, intmax_t);
	number = (long int)number;
	return (number);
}

void	ft_spec_d_i(t_flist *list, va_list *ap)
{
	intmax_t	number;
	int			len_arg;
	int			pres;
	int 		sign;

	pres = g_pres;
	number = (g_sr != 'D' ? ft_signed_size(list, ap) : ft_spec_D(ap));
	sign = ((number < 0 || (number >= 0 && (list->p || list->s))) ? 1 : 0);
	list->res = ft_itoa_base(number, 10);
	len_arg = (number == 0 && g_pres == 0) ? 0 : (int)ft_strlen(list->res);
	if (sign > 0)
		g_width--;
	if (g_width > -1)
	{
		if (list->m == 0 && ((list->zo && g_pres >= 0) || list->zo == 0))
		{
			g_width = g_width - ((g_pres > len_arg) ? g_pres : len_arg);
			ft_put_len_space(g_width, ' ');
		}
	}
	ft_sign(list, number, len_arg, pres);
	ft_write_number_d_i(list, number, len_arg);
	free(list->res);
}

int 		leng_wchar(wchar_t arg)
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

void	ft_spec_c_C(t_flist *list, va_list *ap)
{
	void	*arg;
	int		len_arg;
	int		j;
	int		space;

	space = 0;
	arg = va_arg(*ap, void *);
	if (g_sr == 'C' || (g_sr == 'c' && list->l == 1))
		list->res = ft_conw_char((wchar_t)arg);
	else
	{
		list->res = ft_strnew(1);
		list->res[0] = (char)arg;
	}
	len_arg = 1;
	j = len_arg;
	if (list->m == 0 && g_width > 0)
	{
		if (list->zo)
			ft_put_len_space(g_width - len_arg, '0');
		else
			ft_put_len_space(g_width - len_arg, ' ');
	}
	if (list->res[0])
	{
		while (j && *(list->res))
		{
			ft_putchar(*(list->res));
			j--;
		}
	}
	if (list->m == 1 && g_width > 0)
		ft_put_len_space(g_width - len_arg, ' ');
	ft_strdel(&(list->res));
}

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
	else if(g_pres >= 0)
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

void	ft_spec_s_S(t_flist *list, va_list *ap)
{
	void	*arg;
	int		len_arg;
	int		pres;
//	int j;
	int k = 0;

	pres = g_pres;
	arg = va_arg(*ap, void *);
	if (g_sr == 'S' || (g_sr == 's' && list->l == 1))
		conv_wstr(list, (wchar_t *)arg);
	else
		if ((char *)arg)
			list->res = ft_strdup((char *)arg);
		else
			list->res = ft_strdup("(null)");
	len_arg = (int)ft_strlen(list->res);
	if (*list->res == '\0')
		ft_put_len_space(g_width, ' ');
	else
	{
		if (g_width > -1)
		{
			if (list->m == 0) //&& ((list->zo && g_pres >= 0) || list->zo == 0))
			{
				//if (g_pres >= 0)
				g_width = g_width - ((g_pres > len_arg) ? len_arg : g_pres);
				if (list->zo)
					ft_put_len_space(g_width, '0');
				else
					ft_put_len_space(g_width, ' ');

			}
		}
		// if (((list->s || list->p) && list->m == 0) && g_width > g_pres)
		// 		ft_put_len_space(1, ' ');
		if (g_pres >= 0|| (g_pres < 0 && list->zo && g_width))
		{
			if (g_pres > len_arg)
			{
				ft_put_len_space(g_pres - len_arg, '0');
				g_pres = len_arg;
			}
			else if (g_pres < 0 && g_width > len_arg)
			{
				ft_put_len_space(g_width - len_arg, '0');
				g_width = len_arg;
			}
		}
		if (len_arg && g_pres >= 0) //|| g_width))
		{
			while (pres > 0 && *(list->res))
			{
				ft_putchar(*(list->res));
				pres--;
				list->res++;
			}
			// if (g_pres > 0)
			// {
			// 	while (pres > 0 && *(list->res))
			// 	{
			// 		ft_putchar(*(list->res));
			// 		pres--;
			// 		list->res++;
			// 	}
			// }
			// else if (g_width > 0)
			// {
			// 	j = g_width;
			// 	while (j > 0 && *(list->res))
			// 	{
			// 		ft_putchar(*(list->res));
			// 		j--;
			// 		list->res++;
			// 		k++;
			// 	}	
			// }
		}
		else
			while (*(list->res))
			{
				ft_putchar(*(list->res));
				list->res++;
				k++;
			}
		g_width = g_width - k;
		if (g_width > -1)
		{
			if (list->m == 1 && ((list->zo && g_pres >= 0) || list->zo == 0))
			{
				g_width = g_width - ((g_pres != -1) ? g_pres : 0);
				ft_put_len_space(g_width, ' ');
			}
		}
	}
}

void	ft_p_p(t_flist *list, int len_arg)
{
	if (len_arg)
		ft_putstr(list->res);
	if (g_width > -1)
	{
		if (list->m == 1 && ((list->zo && g_pres >= 0) || list->zo == 0))
		{
			g_width = g_width - ((g_pres > len_arg) ? g_pres : len_arg);
			ft_put_len_space(g_width, ' ');
		}
	}
}

void	ft_sign_p(t_flist *list, int len_arg, int pres)
{
	if (list->s || list->p)
			ft_put_len_space(1, ' ');
	if (pres >= 0|| (pres < 0 && list->zo && g_width))
	{
		if (pres > len_arg)
		{
			ft_put_len_space(pres - len_arg, '0');
			pres = len_arg;
		}
		else if (g_pres < 0 && g_width > len_arg)
		{
			ft_put_len_space(g_width - len_arg, '0');
			g_width = len_arg;
		}
	}
}

void	ft_p(t_flist *list)
{
	int		len_arg;
	int		sign;
	int		pres;

//	ft_s_n(list);
	pres = g_pres;
//	len_arg = (int)ft_strlen(list->str);
	// if (g_width >= 0 && list->m == 0)
	// {
	// 	g_width = g_width - (len_arg);
	// 	ft_put_len_space(g_width, ' ');
	// }


	sign = (list->p || list->s) ? 1 : 0;
	list->res = list->str;
	len_arg = (int)ft_strlen(list->res);
	if (sign > 0)
		g_width--;
	if (g_width > -1)
	{
		if (list->m == 0 && ((list->zo && g_pres >= 0) || list->zo == 0))
		{
			g_width = g_width - ((g_pres > len_arg) ? g_pres : len_arg);
			ft_put_len_space(g_width, ' ');
		}
	}
	ft_sign_p(list, len_arg, pres);
	ft_p_p(list, len_arg);
	free(list->res);

}

void	ft_delete_g_varib(t_flist *list)
{
	list->prs = 0;
	g_width = 0;
	g_sr = 0;
	g_pres = -1;
	g_count_arg = 0;
}

int		ft_atoi_wl(t_flist *list, int *i)
{
	int		res;

	res = 0;
	while (list->str[*i] >= '0' && list->str[*i] <= '9')
	{
		res = res * 10 + (list->str[*i] - '0');
		list->str[*i] = ';';
		(*i)++;
	}
	(*i)--;
	return (res);
}


void	ft_wid_len(t_flist *list)
{
	int		i;

	i = 0;
	while (list->str[i])
	{
		if (list->str[i - 1] != '.' && list->str[i] >= 48 &&
			list->str[i] < 58 && list->str[i] != '0')
			g_width = ft_atoi_wl(list, &i);
		else if (list->d == 1 && list->str[i] == '.')
		{
			i++;
			g_pres = ((list->str[i] >= 48 && list->str[i] < 58) ?
				ft_atoi_wl(list, &i) : 0);
		}
		i++;
	}
}

void	ft_list_lh(t_flist *list)
{
	int		i;
	int		count_h;
	int		count_l;

	i = 0;
	count_h = 0;
	count_l = 0;
	while (list->str[i])
	{
		if (list->str[i] == 'h')
			count_h++;
		else if (list->str[i] == 'l')
			count_l++;
		i++;
	}
	((count_h && count_h % 2 == 0) ? list->hh = 1 : 0);
	((list->hh == 1) ? list->h = 0 : 1);
	((count_l && count_l % 2 == 0) ? list->ll = 1 : 0);
	((list->ll == 1) ? list->l = 0 : 1);
}

void	ft_init_flags(t_flist *list, char *tmp, int i)
{
	int		k;

	k = -1;
	ft_strncpy(list->str, tmp, (size_t)i - 1);
	while (list->str[++k])
		(list->str[k] == '.' ? list->d = 1 : 0);
	k = -1;
	// while (*tmp)
	// {
	// 	(*tmp == '.' ? list->d = 1 : 0);
	// 	tmp++;
	// }
	ft_wid_len(list);
	while (list->str[++k])
	{
		(list->str[k] == '-' ? list->m = 1 : 0);
		(list->str[k] == '+' ? list->p = 1 : 0);
		(list->str[k] == ' ' ? list->s = 1 : 0);
		(list->str[k] == '#' ? list->hs = 1 : 0);
		(list->str[k] == '0' ? list->zo = 1 : 0);
		(list->str[k] == 'h' ? list->h = 1 : 0);
		(list->str[k] == 'l' ? list->l = 1 : 0);
		(list->str[k] == 'j' ? list->j = 1 : 0);
		(list->str[k] == 'z' ? list->z = 1 : 0);
	}
	if (list->h == 1 || list->l == 1)
		ft_list_lh(list);
	list->zo = (list->m == 1) ? 0 : list->zo;
}

void	ft_list_zero(t_flist *list, int i)
{
	// if (list->str != NULL)
	// 	free(list->str);
	if ((list->str = (char *)malloc((i + 1) * sizeof(char))) != NULL)//strnew
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
	if (start[i + 1])
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

void	ft_just_do_it(char **start, va_list *ap)
{
	t_flist		*list;
	char		*tmp;
	int			i;

	tmp = *start;
	*start = ft_strnchar(*start, "%sSpdDioOuUxXcC");
	i = *start - tmp;
	if ((list = (t_flist *)malloc(sizeof(t_flist))) == NULL)
		return ;
	ft_list_zero(list, i);
	ft_init_flags(list, tmp + 1, i);
	if (g_sr == '%')
		ft_p(list);
	if (g_sr == 'd' || g_sr == 'i' || g_sr == 'D')
		ft_spec_d_i(list, ap);
	if (g_sr == 'u' || g_sr == 'U')
		ft_spec_u_U(list, ap);
	if (g_sr == 'o' || g_sr == 'O')
		ft_spec_o_O_x_X(list, ap);
	if (g_sr == 'x' || g_sr == 'X' || g_sr == 'p')
		ft_spec_x_X(list, ap);
	if (g_sr == 's' || g_sr == 'S')
		ft_spec_s_S(list, ap);
	if (g_sr == 'c' || g_sr == 'C')
		ft_spec_c_C(list, ap);
	ft_delete_g_varib(list);
}

void		ft_realise(const char *format, va_list *ap)
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
		else
			if (*end != '\0')
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


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


/*
int main(void)
{


	// const char A[] = "this is tEEEEst!";

	// printf("====||$-05.3 76 .9s|\t\t|$+3.5s|\t|$-7s|\t|$07.3s|==========\n");
	// printf("|orig = ||%-05.3 7 .8s|\t\t|%+3.5s|\t|%-7s|\t|%07.3s|\n",A, A,A,NULL);
	// ft_printf("|my =   ||%-05.3 7 .8s|\t\t|%+3.5s|\t|%-7s|\t|%07.3s|",A, A,A,NULL);
	// printf("\n");printf("\n");



	// printf("====|$$m|   |$yyyy$|   |$6t$|   |$-t$|   |$+9tt$|==========\n");
	// printf("|orig = |%%m|   |%yyyy%|   |%6t%|   |%-t%|   |%+9tt%|\n");
	// ft_printf("|my =   |%%m|   |%yyyy%|   |%6t%|   |%-t%|   |%+9tt%|\n");
	// printf("\n");printf("\n");

	// printf("====|$-6$|   |$6$|   |$6.2$|   |$-06$|   |$-06.3$|==========\n");
	// printf("|orig = |%-6%|   |%6%|   |%6.2%|   |%-06%|   |%-06.3%|\n");
	// ft_printf("|my =   |%-6%|   |%6%|   |%6.2%|   |%-06%|   |%-06.3%|\n");
	// printf("\n");printf("\n");

	// printf("====|$-6m$|   |$6yyya$|   |$6.2$|   |$-06$|   |$-06.3%|==========\n");
	// printf("|orig = |%-6m%|   |%6yyya%|   |%6.2%|   |%-06%|   |%-06.3%|\n");
	// ft_printf("|my =   |%-6m%|   |%6yyya%|   |%6.2%|   |%-06%|   |%-06.3%|\n");
	// printf("\n");printf("\n");

	// printf("====|#-6#m|   |#6##yyya#|   |#z6.2#|   |#-06r#|   |#-06.3t#|==========\n");
	// printf("|orig = |%-6%m|   |%6%%yyya%|   |%z6.2%|   |%-06r%|   |%-06.3t%|\n");
	// ft_printf("|my =   |%-6%m|   |%6%%yyya%|   |%z6.2%|   |%-06r%|   |%-06.3t%|\n");
	// printf("\n");printf("\n");

	// printf("====|$-6.12$m|   |$06$$yyya$|   |$ z6.2$|   |$+-06r$|   |$ 0 +-06.3t$|==========\n");
	// printf("|orig = |%-6.12%m|   |%06%%yyya%|   |% z6.2%|   |%+-06r%|   |% 0 +-06.3t%|\n");
	// ft_printf("|my =   |%-6.12%m|   |%06%%yyya%|   |% z6.2%|   |%+-06r%|   |% 0 +-06.3t%|\n");
	// printf("\n");printf("\n");



	// char	*s;
	// char a = 'a';


 	//s[] = "this is tEEEEst!";
// //	printf("%%|%0-20%|%+3%|%#4.2%|%-20  9.3yasa |%|\n");
// 	printf("====|$-2.3c|($3d)\t|$-2.5c|($3d)\t|$-2.0c|($3d)", a, a, a+5,a+5,a+10,a+10|==========\n");

	// printf("%z19ls||%  60 s||%+3s||%#4.12s||%-20  9.3yasa |%|\n",s, s, s, s);
	// ft_printf("%%|%-20%|%+3%|%#4.2%|%-20  9.3yasa |%|\n");



	// PRINTF("|%-+2c|(%3d)\t|%-3c|(%3d)\t|%4c|(%3d)", a, a, a+5,a+5,a+10,a+10);
	// PRINTF("|%+-2.3c|(%3d)\t|%-2.0c|(%3d)\t|%-2.1c|(%3d)", a, a, a+5,a+5,a+10,a+10);
	// PRINTF("|%0+3c|(%3d)\t|%+3c|(%3d)\t|%+c|(%3d)", a, a, a+5, a+5, a+10, a+10);
	// PRINTF("|%3.4c|(%3d)\t|%+3.4c|(%3d)\t|%7.4c|(%3d)", a, a, a+5, a+5, a+10, a+10);

	// PRINTF("|%-3w|(%3w)\t|%3Z|(%3Z)\t|%Q|(%3Q)");
	// PRINTF("|%3h|\t|%3l|\t|%3hhll|\t|%3llhhllQ|\t|%3z|\t|%3j|\t|%3J|");
	// PRINTF("|%-3c|\t|%3c|\t|%c|\t|%-03c|\t|%03c|\t|%.c|\t|%.5c|\t|%.C|\t|%.5C|", 0,0,0,0,0,0,0,0,0);


	printf("====|$S|\t|$S|\t|$C|\t|$S|  Wide sample string.., 米, 米==========\n");
	printf("|orig = |%S|\t|%S|\t|%C|\t|%S|\n",L"Wide sample string..",L"米",L'米',L"");
	ft_printf("|my =   |%S|\t|%S|\t|%C|\t|%S|\n",L"Wide sample string..",L"米",L'米',L"");
	printf("\n");printf("\n");

	
	printf("|##6.7d|\t|##-12.7d|\t|##.7d|\t|##09.7d|\t|##02.7d|\n");
	printf("|orig = |%#6.7d|\t|%#-12.7d|\t|%#.7d|\t|%#09.7d|\t|%#02.7d|\n", 8400,8400,0,8400,8400);
	ft_printf("|my =   |%#6.7d|\t|%#-12.7d|\t|%#.7d|\t|%#09.7d|\t|%#02.7d|\n", 8400,8400,0,8400,8400);
	printf("\n");printf("\n");

	return (0);
}

*/