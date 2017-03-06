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

void	f(int value, int base, char *s, int *i)
{
	char	*tmp;

	tmp = "0123456789ABCDEF";
	if (value <= -base || value >= base)
		f(value / base, base, s, i);
	s[(*i)++] = tmp[(value % base) < 0 ? -(value % base) : (value % base)];
}

char	*ft_itoa_base(int value, int base)
{
	int		i;
	char	*s;

	i = 0;
	if (base < 2 || base > 16 || !(s = (char *)malloc(32)))
		return (0);
	if (base == 10 && value < 0)
		s[++i] = '-';
	f(value, base, s, &i);
	s[i] = '\0';
	return (s);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
	char			g_spec;

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
void	ft_delete_g_varib(t_flist *list)
{
	list->prs = 0;
	g_width = 0;
	g_spec = 0;
	g_pres = 0;
}

int		ft_atoi_wl(char *str, int *i)
{
	int		res;

	res = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		res = res * 10 + (str[*i] - '0');
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
			g_width = ft_atoi_wl(list->str, &i);
		if (list->d == 1 && list->str[i] == '.')
		{
			i++;
			g_pres = ft_atoi_wl(list->str, &i);
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
		if (list->str[i] == 'l')
			count_l++;
		i++;
	}
	((count_h % 2 == 0) ? list->hh = 1 : 0);
	((list->hh == 1) ? list->h = 0 : 1);
	((count_l % 2 == 0) ? list->ll = 1 : 0);
	((list->ll == 1) ? list->l = 0 : 1);
}

void	ft_init_flags(t_flist *list, char *tmp, int i)
{
	int		k;

	k = -1;
	ft_strncpy(list->str, tmp, (size_t)i - 1);
	while (list->str[++k])
	{
		(list->str[k] == '-' ? list->m = 1 : 0);
		(list->str[k] == '+' ? list->p = 1 : 0);
		(list->str[k] == ' ' ? list->s = 1 : 0);
		(list->str[k] == '#' ? list->hs = 1 : 0);
		(list->str[k] == '0' ? list->zo = 1 : 0);
		(list->str[k] == '.' ? list->d = 1 : 0);
		(list->str[k] == 'h' ? list->h = 1 : 0);
		(list->str[k] == 'l' ? list->l = 1 : 0);
		(list->str[k] == 'j' ? list->j = 1 : 0);
		(list->str[k] == 'z' ? list->z = 1 : 0);
	}
	if (list->h == 1 || list->l == 1)
		ft_list_lh(list);
	ft_wid_len(list);
	printf("\nwidth = %d\n", g_width);
	printf("pres = %d\n", g_pres);
	// printf("\n\nm = %d\n", list->m);
	// printf("p = %d\n", list->p);
	// printf("s = %d\n", list->s);
	// printf("hs = %d\n", list->hs);
	// printf("zo =%d\n", list->zo);
	// printf("d = %d\n", list->d);
	// printf("h = %d\n", list->h);
	// printf("hh = %d\n", list->hh);
	// printf("l = %d\n", list->l);
	// printf("ll = %d\n", list->ll);		
	// printf("j = %d\n", list->j);
	// printf("z = %d\n\n", list->z);
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
				g_spec = spec[k];
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
	t_flist	*list;
	char	*tmp;
	int		i;
	va_list *aa;

	aa = ap;

	tmp = *start;
	*start = ft_strnchar(*start, "%sSpdDioOuUxXcC");
	i = *start - tmp;
	if ((list = (t_flist *)malloc(sizeof(t_flist))) == NULL)
		return ;
	ft_list_zero(list, i);
	ft_init_flags(list, tmp + 1, i);
	ft_delete_g_varib(list);
}

int		ft_realise(const char *format, va_list *ap, int i)
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
			start = end;
		}
		else
			if (*end != '\0')
				i++;
		end++;
	}
	ft_putnstr(start, end - start);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, format);
	i = ft_realise(format, &ap, i);
	va_end(ap);
	return (i);
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
//	int		i;
	// int		*a;
	// *a = "65, 66, 67";

//	i = ft_printf("ssd");
//	ft_printf("num = 123%456789\n");
//	printf("%s\n %d \n%c\n\n", "wdewew", 123, 'a');
//	printf("d = %d\n",ft_printf("%d", 123));
	// printf("%#x\n", 99);
	// printf("kharacters: %c %c\n", 'a', 65);
	// printf("Decimals: %d %ld\n", 1977, 650000L);
	// printf("Preceding with blanks: %10d \n", 1977);
	// printf("Preceding with zeros: %010d \n", 1977);
	// printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	// printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	// printf("Width trick: %*d \n", 5, 10);
	// printf("%s \n", "A string");
	// printf("%h5.2+f\n", 123.0);
//	printf("count_ft = %d\n", ft_printf("%123456789asdf.;'\""));
//    printf("%%%%\n");
//	ft_printf("1 = asd %%asd %d|\n", 123);
//    printf("2 = asd %%asd %d|\n", 123);
//    ft_printf("-------------------------------\n");
//    ft_printf("3 = sdf&& %% as%% %% %d %s|\n", 159, "QWERT");
//    printf("4 = sdf&& %% as%% %% %d %s|\n", 159, "QWERT");
//    ft_printf("--ft-----------------------------\n");
//    printf("n_ft = %d\n", ft_printf("5 = asd %%asd %s|\n", "QW"));
//    ft_printf("---pr----------------------------\n");
//    printf("n_p = %d\n", printf("6 = asd %%asd %s|\n", "QW"));
//
//    ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
//    ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
//    ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
//    ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
 //    printf("5 = %---+-.9h  000d|\n", 123);
 //    printf("6 = %---+-h  000d|\n", 123);
	// printf("%c%c%c\n", 209, 133);
	// printf("%c%c\n", 209, 131);
	// printf("%c%c%c\n",208, 185);
 //    printf("%c%c\n", 209, 134);
 //    printf("%c%c\n", 209, 135);
 //    printf("%c%c\n", 209, 136);
 //    printf("%c%c%c\n",208, 186);
 //    printf("%c%c%c\n",208, 187);
//	printf("123:%-d 456:%+d -789:%-d 951:%0d 753:%0+d 654:%+0d 852:%10.7d 258:% 5d 321:%    .8d\n",
//			123, 456, -789, 951, 753, 654, 852, 258, 321);
	//printf("123:%-+0#  l 110d| 456:%-10d|\n", 123, -456);
//	printf("%012.3b%%\n");
	ft_printf("asma%- 0 # hh z 103.8lll .45 s   k%#+-0   llkzjlhhh       p", 10);
//	printf("%c%c%c%c%c%c%c", 209, 133, 209, 131, 208, 185, 10);

	return (0);
}
