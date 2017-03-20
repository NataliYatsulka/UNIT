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

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_nbr(intmax_t nb)
{
	if (nb < 0)
	{
		nb = (-1) * nb;
	}
	if (nb > 9)
	{
		ft_put_nbr(nb / 10);
		ft_put_nbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (s == '\0')
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
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

	tmp = "0123456789ABCDEF";
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


// // відповідно до флагу, обробляє arg
// void	ft_flag(char *s, va_list *ap, char flag, int *i)
// {
// 	void	*arg;
// 	char *a;
// 	s_f_list	list;

// 	if (list == NULL)
	
// 	// if (flag == 'd')
// 	// {
// 	// 	arg = va_arg(*ap, void *);
// 	// 	a = ft_itoa_base((int)arg, 10);
// 	// }
// 	// else
// 	// 	if (flag == 's')
// 	// 	{
// 	// 		arg = va_arg(*ap, void *);
// 	// 		a = (char *)arg;
// 	// 	}
// 	ft_putstr(a);
// }


// // повертає: s - обролену
// char	*ft_just_do_it(char *s, va_list *ap)
// {
// 	char	flag;

// 	s++;
// 	if (*s == '%')
// 	{
// 		write(1, "%", 1);
// 		i++;
// 	}
// 	if (*s == 'd')
// 	{
// 		flag = 'd';
// 		ft_flag(s, ap, flag, &i);
// 	}
// 	if (*s == 's')
// 	{
// 		flag = 's';
// 		ft_flag(s, ap, flag, &i);
// 	}
// 	return (s);
// }

/*
	char			g_sr;

	char			*str;//рядок з флагами, необроблений
	int				m;//-
	int				p;//+
	int				s;//space
	int				hs;//#
	int				zo;//0
	int				w;//width
	int				prs;//precision
	char			*res;//рядок з обробленими флагами
	int				h;
	int				hh;
	int				j;
	int				l;
	int				ll;
	int				z;
*/

// void	ft_spec_len(t_flist *list)
// {
// 	if (list->j || list->z || list->ll || list->l || list->h || list->hh)
// 	{
// 		if (list->j)


// 	}
// }

// void	ft_flags(t_flist *list, intmax_t *num)
// {
// 	if (list->m)
// 	{
// 		printf("%d", num);
// 		while (g_width > 0)
// 		{
// 			printf(" ");
// 			g_width--;
// 		}
// 	}
// }

uintmax_t	ft_unsigned_size(t_flist *list, va_list *ap)
{
	uintmax_t	number;

	number = va_arg(*ap, intmax_t);
	g_count_arg++;
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
	g_count_arg++;
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

void	ft_spec_d_i(t_flist *list, va_list *ap)
{
	intmax_t	number;
	int			len_arg;
	int			pres;
//	int 		space;
//	int 		zero;
	int 		sign;

	pres = g_pres;
	number = ft_signed_size(list, ap);
//	sign = ((number < 0 || (number > 0 && (list->p || list->s))) ? 1 : 0);
	list->res = ft_itoa_base(number, 10);
	len_arg = (int)ft_strlen(list->res);
	if (number < 0 || ((list->p || list->s) && number > 0))
		g_width--;
	if (g_width > -1)
	{
		sign = ((g_count_arg > 0 && (list->m == 1 || list->zo == 1 ||
			list->s == 1 || list->p == 1 || number < 0) && g_pres > 0) ? 1 : 0);
		if (list->m == 0 && ((list->zo && g_pres >= 0) || list->zo == 0))
		{
			g_width = g_width - sign - ((g_pres > len_arg) ? g_pres : len_arg);
			ft_put_len_space(g_width, ' ');
		}
	}
	if (list->s || list->p || number < 0)
	{
		if (number < 0)
			write(1, "-", 1);
		else if (list->p && number >= 0)// >= ??
			write(1, "+", 1);
		else if (list->s && number > 0)
			write(1, " ", 1);
	}
	if (pres || (pres < 0 && list->zo && g_width))
	{
		if (pres > len_arg)
			while (pres - len_arg)
			{
				write(1, "0", 1);
				pres--;
			}
		else if (g_width > len_arg || (g_pres > 0 && g_width > 0))
		{
			while (g_width - len_arg)
			{
				if (list->zo)
					write(1, "0", 1);
				else if (list->s)
					write(1, " ", 1);
				g_width--;
			}
		}
		ft_put_nbr(number);
	}
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
	free(list->res);
    
	// if (number < 0 || list->m || list->s)
	// 	g_width--;
	// if (number < 0)
	// 	write(1, "-",1);
	// else if (number >= 0)
	// {
	// 	i = (int)ft_strlen(ft_itoa_base(number, 10));
	// 	if (i < g_width)
	// 		while ((g_width - i) > 0)
	// 		{
	// 			write(1, "/", 1);
	// 			g_width--;
	// 		}
	// }
	// if (number == 0 && g_pres)
	// 	list->res = ft_strnew(1);
	// else
	// 	list->res = ft_itoa_base(number, 10);
	// ft_putstr(list->res);
	// free(list->res);
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
	return (res);
}

void	ft_wid_len(t_flist *list)
{
	int		i;

	i = 0;
	while (list->str[i])
	{
		if (list->str[i] > 48 && list->str[i] < 58)
			g_width = ft_atoi_wl(list, &i);
		if (list->d == 1 && list->str[i] == '.')
		{
			i++;
			g_pres = ft_atoi_wl(list, &i);
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
	if ((list = (t_flist *)malloc(sizeof(t_flist))) == NULL)
		return ;
	ft_list_zero(list, i);
	ft_init_flags(list, tmp + 1, i);
	if (g_sr == 'd' || g_sr == 'i')
		ft_spec_d_i(list, ap);
	// if (g_sr == 'u' || g_sr == 'U' || g_sr == 'o' || g_sr == 'O'
	// 	|| g_sr == 'x' || g_sr == 'X')
	// 	ft_unsigned_size(list, ap);
	// if (g_sr == '%' || || g_sr == '%')
	// 	ft_p_proc(list);
	// if (g_sr == 'D' || g_sr == 's' || g_sr == 'S' || g_sr == 'S' ||
	// 	g_sr == 'c' || g_sr == 'C')
	// 	ft_char_sp(list, ap);
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
	g_count_arg = 0;
    ft_realise(format, &ap);
	va_end(ap);
	return (g_res);
}

// s - строка в яку записуємо результат даних оброблених специфікаторами
// повертає: число виведених символів
// int		ft_realise(const char *format, va_list *ap, int i)
// {
// //	t_flag	list;
// 	char	*s;

// 	s = (char *)format;
// 	while (*s)
// 	{
// 		if (*s && *s != '%')
// 		{
// 			write(1, s, 1);
// 			i++;
// 		}
// 		else
// 			if (*s && *s == '%')
// 				s  = ft_just_do_it(s, ap, i);					
// 		s++;
// 	}
// 	while (*s)
// 	{
// 		printf("%c", *s);
// 		s++;
// 	}
// 	printf("\n");
// 	return (i);
// }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


int main(void)
{

	ft_printf("M1 = %0+ll29zdA%0.5dqqqq%z00000lhl+lllh-#d%0+10.5d/||\n", -123456789123456, 2345, 987654321, 0);
	printf("O1 = %0+ll29zdA%0.5dqqqq%z0000+0lhllllh-#d%0+10.5d/||\n", -123456789123456, 2345, 987654321, 0);
	ft_printf("M2 = %0 .18-16d||\n", -9876543);
	printf("O2 = %0 .18-16d||\n", -9876543);
	ft_printf("M3 = %7d||\n", -12345);
	printf("O3 = %7d||\n", -12345);
	ft_printf("M4 = %018.15d||\n", -123456789);
	printf("O4 = %018.15d||\n", -123456789);
	ft_printf("M5 = %0+-12.5 0d/||\n", 55);
	printf("O5 = %0+-12.5 0d/||\n", 55);


	return (0);
}
