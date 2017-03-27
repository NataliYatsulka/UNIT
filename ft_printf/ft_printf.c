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
			g_res++;
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
		g_res++;
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

uintmax_t	ft_spec_O(t_flist *list, va_list *ap)
{
	uintmax_t	number;

	number = va_arg(*ap, uintmax_t);
	number = (unsigned long int)number;
	return (number);
}

void	ft_write_number_u(t_flist *list, uintmax_t number, int len_arg)
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

void	ft_sign_u(t_flist *list, uintmax_t number, int len_arg, int pres)
{
	// if (list->s || list->p)
	// {
	// 	// if (list->p && number >= 0)
	// 	// 	ft_put_len_space(1, '+');
	// 	if (list->s)
	// 		ft_put_len_space(1, ' ');
	// }
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

void	ft_spec_u_U(t_flist *list, va_list *ap)
{
	uintmax_t	number;
	int			len_arg;
	int			pres;
	int 		sign;

	pres = g_pres;
	number = (g_sr != 'U' ? ft_unsigned_size(list, ap) : ft_spec_O(list, ap));
	sign = (list->p || list->s) ? 1 : 0;
	list->res = ft_itoa_base(number, 10);
	len_arg = (number == 0 && g_pres == 0) ? 0 : (int)ft_strlen(list->res);
	// if (sign > 0)
	// 	g_width--;
	if (g_width > -1)
	{
		if (list->m == 0 && ((list->zo && g_pres >= 0) || list->zo == 0))
		{
			g_width = g_width - ((g_pres > len_arg) ? g_pres : len_arg);
			ft_put_len_space(g_width, ' ');
		}
	}
	ft_sign_u(list, number, len_arg, pres);
	ft_write_number_u(list, number, len_arg);
	free(list->res);
}

void	ft_sign_x(t_flist *list, int len_arg, int pres, uintmax_t number)
{
	if (list->hs && number != 0)
	{
		ft_put_len_space(1, '0');
		if (g_sr == 'x')
			ft_put_len_space(1, 'x');
		else
			ft_put_len_space(1, 'X');
		// if (pres > 1)
		// 	pres = pres - 2;
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

void	ft_spec_x_X(t_flist *list, va_list *ap)
{
	uintmax_t	number;
	int			len_arg;
	int			pres;
	int			sign;

	pres = g_pres;
	//number = (g_sr != 'X' ? ft_unsigned_size(list, ap) : ft_spec_X(list, ap));
	number = ft_unsigned_size(list, ap);
	list->res = ft_itoa_base(number, 16);
	len_arg = (list->res == 0 && g_pres == 0) ? 0 : (int)ft_strlen(list->res);
	if (g_sr == 'x' || g_sr == 'X')
	{
		if (list->hs)
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
//	if (list->hs)
//		ft_put_len_space(1, '0');
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
	// if (number == 0 && g_pres == 0 && list->hs)
	// 	list->res = ft_strnew(1);
}

void	ft_spec_o_O_x_X(t_flist *list, va_list *ap)
{
	uintmax_t	number;
	int			len_arg;
	int			pres;
	int			sign;

	pres = g_pres;
	number = (g_sr != 'O' ? ft_unsigned_size(list, ap) : ft_spec_O(list, ap));
	list->res = ft_itoa_base(number, 8);
	len_arg = (list->res == 0 && g_pres == 0) ? 0 : (int)ft_strlen(list->res);
	if (g_sr == 'o' || g_sr == 'O')
	{
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
	else
	{
		write(1, "YES", 3);
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

intmax_t	ft_spec_D(t_flist *list, va_list *ap)
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
	number = (g_sr != 'D' ? ft_signed_size(list, ap) : ft_spec_D(list, ap));
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
		list->str[*i] = 'A';
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
		if (list->str[i - 1] != '.' && list->str[i] >= 48 && list->str[i] < 58 && list->str[i] != '0')
			g_width = ft_atoi_wl(list, &i);
		else if (list->d == 1 && list->str[i] == '.')
		{
			i++;
			g_pres = ((list->str[i] >= 48 && list->str[i] < 58) ? ft_atoi_wl(list, &i) : 0);		
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
	while (*tmp)
	{
		(*tmp == '.' ? list->d = 1 : 0);
		tmp++;
	}
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
	g_count_pres = 0;
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
	// if (g_sr == '%' || g_sr == 'p')
	// 	ft_p_proc(list);
	if ((list = (t_flist *)malloc(sizeof(t_flist))) == NULL)
		return ;
	ft_list_zero(list, i);
	ft_init_flags(list, tmp + 1, i);
	if (g_sr == 'd' || g_sr == 'i' || g_sr == 'D')
		ft_spec_d_i(list, ap);
	if (g_sr == 'u' || g_sr == 'U')
		ft_spec_u_U(list, ap);
	if (g_sr == 'o' || g_sr == 'O')
		ft_spec_o_O_x_X(list, ap);
	if (g_sr == 'x' || g_sr == 'X')
		ft_spec_x_X(list, ap);
	// if (g_sr == 's' || g_sr == 'S')
	// 	ft_spec_s_S(list, ap);
	// if (g_sr == 'c' || g_sr == 'C')
	// 	ft_spec_c_C(list, ap);
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
				g_res++;
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


// int main(void)
// {
// // 	// ft_printf("__________________spec d & i_____________________\n");
// // 	// ft_printf("M1 = %0+ll29zdA%0.5dqqqq%z00000lhl+lllh-#d%0+10.5d/||\n",
// // 	// 	-123456789123456, 2345, 987654321, 0);
// // 	// printf("O1 = %0+ll29zdA%0.5dqqqq%z0000+0lhllllh-#d%0+10.5d/||\n",
// // 	// 	-123456789123456, 2345, 987654321, 0);
// // 	// ft_printf("M1 = %0+10.0d/||\n", 0);
// // 	// printf("O1 = %0+10.0d/||\n", 0);
// // 	// ft_printf("M2 = %0 .-16d||\n", -9876543);
// // 	// printf("O2 = %0 .-16d||\n", -9876543);
// // 	// ft_printf("M3 = %7d||\n", -12345);
// // 	// printf("O3 = %7d||\n", -12345);
// // 	// ft_printf("M4 = %018.15d||\n", -123456789);
// // 	// printf("O4 = %018.15d||\n", -123456789);
// // 	// ft_printf("M5 = %0+-12.5 0d/||\n", 55);
// // 	// printf("O5 = %0+-12.5 0d/||\n", 55);
// // 	// ft_printf("__________________spec D_____________________\n");
// // 	// printf("O1 = %+0 +12.8D||\n", -1234567891234567);
// // 	// ft_printf("M1 = %+0 +12.8D||\n", -1234567891234567);
// // 	// // printf("D = %d\n", ft_printf("M4 = %018.15d||\n", -123456789));
// // 	// // printf("D = %d\n", printf("M4 = %018.15d||\n", -123456789));
// // 	// printf("O = %d\n", printf("O1 = %0+10.0d/||\n", 0));
// // 	// printf("M = %d\n", ft_printf("O1 = %0+10.0d/||\n", 0));
// // 	// printf("O=%+0 28.22D||\n", 12345678912345678912);
// // 	// ft_printf("M=%+0 28.22D||\n", 12345678912345678912);
// // 	// printf("O4 =%20d||\n", 123456);
// // 	// ft_printf("M4 =%20d||\n", 123456);

// // 	ft_printf("__________________spec o_____________________\n");

// // 	printf("---------------+ 20.8---------- 123456 -------------\n");

// // 	printf("O1 =%-+ 20.8o||\n", 123456);
// // 	ft_printf("M1 =%-+ 20.8o||\n", 123456);

// // 	printf("--------------- -#+ 20.8---------- -123456 -------------\n");

// // 	printf("O11 =%-#+ 20.8o||\n", -123456);
// // 	ft_printf("M11 =%-#+ 20.8o||\n", -123456);

// // 	printf("--------+ #17.10----------------  123456--------------\n");

// // 	printf("O2 =%-+ #17.10o||\n", 123456);
// // 	ft_printf("M2 =%-+ #17.10o||\n", 123456);

// // 	printf("-------------- - 0 #25.20--------------- -123456 ---------\n");

// // 	printf("O3 =%- 0 #25.20o||\n", -123456);
// // 	ft_printf("M3 =%- 0 #25.20o||\n", -123456);

// // 	printf("----------#12-------------------- 123456-------\n");

// // 	printf("O4 =%#12o||\n", 123456);
// // 	ft_printf("M4 =%#12o||\n", 123456);

// // 	printf("-------------#12.hh------------------ 123456------\n");

// // 	printf("O5 =%#12.hho||\n", 123456);
// // 	ft_printf("M5 =%#12.hho||\n", 123456);

// // 	printf("-------#12.hh--------------- 0---------------\n");

// // 	printf("O6 =%#12.0hho||\n", 0);
// // 	ft_printf("M6 =%#12.0hho||\n", 0);

// // 	printf("-------#12hh--------------- 0---------------\n");

// // 	printf("O7 =%# 0 12.hho||\n", 1);
// // 	ft_printf("M7 =%# 0 12.hho||\n", 1);

// // 	printf("-------# 0 12hh--------------- 0---------------\n");

// // 	printf("O8 =%# 0 12hho||\n", 0);
// // 	ft_printf("M8 =%# 0 12hho||\n", 0);

// // 	printf("-------# 0 12hh--------------- -6---------------\n");

// // 	printf("O8_1 =%# 0 12hho||\n", -6);
// // 	ft_printf("M8_1 =%# 0 12hho||\n", -6);

// // 	printf("-------# 12hh--------------- 0---------------\n");

// // 	printf("O9 =%# 12hho||\n", 0);
// // 	ft_printf("M9 =%# 12hho||\n", 0);

// // 	printf("-------# 12hh--------------- 1---------------\n");

// // 	printf("O_10 =%# 12hho||\n", 1);
// // 	ft_printf("M_10 =%# 12hho||\n", 1);

// // 	printf("-------# 12hh--------------- 1---------------\n");

// // 	printf("O_11 =%# 12hho||\n", 0);
// // 	ft_printf("M_11 =%# 12hho||\n", 0);

// 	// printf("The number of bits in a byte %d\n", CHAR_BIT);

// 	// printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
// 	// printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
// 	// printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

// 	// printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
// 	// printf("The maximum value of SHORT INT = %d\n", SHRT_MAX); 

// 	// printf("The minimum value of INT = %d\n", INT_MIN);
// 	// printf("The maximum value of INT = %d\n", INT_MAX);

// 	// printf("The minimum value of CHAR = %d\n", CHAR_MIN);
// 	// printf("The maximum value of CHAR = %d\n", CHAR_MAX);

// 	// printf("The minimum value of LONG = %ld\n", LONG_MIN);
// 	// printf("The maximum value of LONG = %ld\n", LONG_MAX);
// 	// printf("\n");
// 	// printf("\n");
// 	// printf("\n");


// 	// int  nmb = 4235;


// 	// printf("-----#-12.8.5i||#12.-8.5i||#-12.-8.5i||#-12.-8.-5i|-----\n");
// 	// printf("orig = |%-12.8.5i||%12.-8.5i||%-12.-8.5i||%-12.-8.-5i|\n", 42, 42, 42, 42);
// 	// ft_printf("my =   |%-12.8.5i||%12.-8.5i||%-12.-8.5i||%-12.-8.-5i|\n", 42, 42, 42, 42);
// 	// printf("\n");
// 	// printf("\n");

// 	// printf("-----|#3.5d|\t\t|#3.5d|\t|#07.5d|\t|#07.5d|-----\n");
// 	// printf("orig = |%3.5d|\t\t|%3.5d|\t|%07.5d|\t|%07.5d|\n",nmb, -nmb, nmb, -nmb);
// 	// ft_printf("my =   |%3.5d|\t\t|%3.5d|\t|%07.5d|\t|%07.5d|\n",nmb, -nmb, nmb, -nmb);
// 	// printf("\n");printf("\n");

// 	// printf("-----&&12.8.10.6d|\t|&&20.8.-12.6d|\t|&&20.8.12.-6d||&&20.-5.12.3d|\t|&&10.8.12.6-d|-----\n");
// 	// printf("orig = |%-12.8.5i||%12.-8.5i||%-12.-8.5i||%-12.-8.-5i|\n", 42, 42, 42, 42);
// 	// ft_printf("my =   |%-12.8.5i||%12.-8.5i||%-12.-8.5i||%-12.-8.-5i|\n", 42, 42, 42, 42);
// 	// printf("\n");printf("\n");

// 	// printf("-----&&12.8.10.6d|\t|&&20.8.-12.6d|\t|&&20.8.12.-6d||&&20.-5.12.3d|\t|&&10.8.12.6-d|-----\n");
// 	// printf("orig = |%12.8.10.6d|\t|%20.8.-12.6d|\t|%20.8.12.-6d||%20.-5.12.3d|\t|%10.8.12.6-d|\n",42,42,42,42,42);
// 	// ft_printf("my =   |%12.8.10.6d|\t|%20.8.-12.6d|\t|%20.8.12.-6d||%20.-5.12.3d|\t|%10.8.12.6-d|\n",42,42,42,42,42);
// 	// printf("\n");	printf("\n");

// 	// printf("==================|#.o #.0o #0.o #0.0o|\t\t|#o #.2o #2.o #2.2o|=========================\n");
// 	// printf("|orig = |%.o %.0o %0.o %0.0o|\t\t|%o %.2o %2.o %2.2o|\t\t\t\t\n",0,0,0,0,0,0,0,0);
// 	// ft_printf("|my =   |%.o %.0o %0.o %0.0o|\t\t|%o %.2o %2.o %2.2o|\t\t\t\t\n",0,0,0,0,0,0,0,0);
// 	// printf("\n");	printf("\n");

// /*
//  |o|:

// Args:   "|%#6.7U|\t|%#-12.7"o|\t|%#.7U|"\t|%#09.7U"|\t|%#02.7U|", 8400,8400,0,8400,8400
// Origin: |0020320|   |0020320     |  |0000000|   |  0020320| |0020320|   ret: 56
//     Ft: |0020320|   |0020320     |  |0000000|   | 0020320|  |0020320|   ret: 104
// */


// 	// printf("===========|$#o $#.0o $#0.o $#0.0o|\t\t|$o $.2o $2.o $2.2o|==========\n");
// 	// printf("|orig = |%.o %.0o %0.o %0.0o|\t\t|%o %.2o %2.o %2.2o|\t\t\t\t\n", 0,0,0,0,0,0,0,0);
// 	// ft_printf("|my =   |%.o %.0o %0.o %0.0o|\t\t|%o %.2o %2.o %2.2o|\t\t\t\t\n", 0,0,0,0,0,0,0,0);
// 	// printf("\n");printf("\n");



// 	// printf("===========|$#6.7X|\t|$#-12.7X|\t|$#.7X|\t|$#09.7X|\t|$#02.7X|==========\n");
// 	// printf("|orig = |%#6X|\t|%#-12X|\t|%#X|\t\t|%#09X|\t|%#02X|\n", 8400,8400,0,8400,8400);
// 	// ft_printf("|my =   |%#6X|\t|%#-12X|\t|%#X|\t\t|%#09X|\t|%#02X|\n", 8400,8400,0,8400,8400);
// 	// printf("\n");printf("\n");

// 	// printf("===========|$#6X|\t|$#-12X|\t|$#X|\t\t|$#09X|\t|$#02X|==========\n");
// 	// printf("|orig = |%#6.7X|\t|%#-12.7X|\t|%#.7X|\t|%#09.7X|\t|%#02.7X|\n", 8400,8400,0,8400,8400);
// 	// ft_printf("|my =   |%#6.7X|\t|%#-12.7X|\t|%#.7X|\t|%#09.7X|\t|%#02.7X|\n", 8400,8400,0,8400,8400);
// 	// printf("\n");printf("\n");

// 	// printf("===========|$#6.2X|\t|$#-12.2X|\t|$#.3X|\t\t|$#09.2X|\t|$#02.2X|==========\n");
// 	// printf("|orig = |%#6.2X|\t|%#-12.2X|\t|%#.3X|\t\t|%#09.2X|\t|%#02.2X|\n", 8400,8400,0,8400,8400);
// 	// ft_printf("|my =   |%#6.2X|\t|%#-12.2X|\t|%#.3X|\t\t|%#09.2X|\t|%#02.2X|\n", 8400,8400,0,8400,8400);
// 	// printf("\n");printf("\n");

// 	// printf("===========|$-#13.10X|\t|$-12#.10X|\t|$-13.10#X|\t|$-13.-9#X|==========\n");
// 	// printf("|orig = |%-#13.10X|\t|%-12#.10X|\t|%-13.10#X|\t|%-13.-9#X|\t\t\n", 25,25,25,25);
// 	// ft_printf("|my =   |%-#13.10X|\t|%-12#.10X|\t|%-13.10#X|\t|%-13.-9#X|\t\t\n", 25,25,25,25);
// 	// printf("\n");printf("\n");

// 	int nmb = 42;

// 	printf("===========|$-11-0u|\t|$-0+11u|\t|$11+u|\t|$-11+u|==========\n");
// 	printf("|orig = |%-11-0u|\t|%-0+11u|\t|%11+u|\t|%-11+u|\t|%0 u|\t\n",nmb,nmb,nmb,nmb,nmb);
// 	ft_printf("|my =   |%-11-0u|\t|%-0+11u|\t|%11+u|\t|%-11+u|\t|%0 u|\t\n",nmb,nmb,nmb,nmb,nmb);
// 	printf("\n");printf("\n");

// 	int nmb3 = 4294934528;

// 	printf("===========||$-11-0u|\t|$-0+11u|\t|$11+u|\t|$-11+u|\t|%0 u||==========\n");
// 	printf("|orig = |%-11-0u|\t|%-0+11u|\t|%11+u|\t|%-11+u|\t|%0 u|\t\n",nmb3,nmb3,nmb3,nmb3,nmb3);
// 	ft_printf("|my =   |%-11-0u|\t|%-0+11u|\t|%11+u|\t|%-11+u|\t|%0 u|\t\n",nmb3,nmb3,nmb3,nmb3,nmb3);
// 	printf("\n");printf("\n");
// 	int nmb1 = 42;

// 	printf("===========|$-11-0U|\t|$-0+11U|\t|$11+U|\t|$-11+U|\t|$0 U|==========\n");
// 	printf("|orig = |%-11-0U|\t|%-0+11U|\t|%11+U|\t|%-11+U|\t|%0 U|\t\n",nmb1,nmb1,nmb1,nmb1,nmb1);
// 	ft_printf("|my =   |%-11-0u|\t|%-0+11u|\t|%11+u|\t|%-11+u|\t|%0 u|\t\n",nmb1,nmb1,nmb1,nmb1,nmb1);
// 	printf("\n");printf("\n");
// 	int nmb2 = 4294934528;

// 	printf("===========|$-11-0U|\t|$-0+11U|\t|$11+U|\t|$-11+U|==========\n");
// 	printf("|orig = |%-11-0U|\t|%-0+11U|\t|%11+U|\t|%-11+U|\t|%0 U|\t\n",nmb2,nmb2,nmb2,nmb2,nmb2);
// 	ft_printf("|my =   |%-11-0U|\t|%-0+11U|\t|%11+U|\t|%-11+U|\t|%0 U|\t\n",nmb2,nmb2,nmb2,nmb2,nmb2);
// 	printf("\n");printf("\n");


// 	return (0);
// }
