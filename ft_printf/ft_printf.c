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

	i = 0;
	if (s == '\0')
		return ;
	while (s[i] && len > 0)
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
	char			*str;//рядок з флагами, необроблений
	int				m;//-
	int				p;//+
	int				s;//space
	int				h;//#
	int				z;//0
	int				w;//width
	int				prs;//precision
	char			*res;//рядок з обробленими флагами
*/

void	ft_list_zero(t_flist *list, int i)
{
	if (list->str != NULL)
		free(list->str);
	list->str = (char *)malloc((i + 1) * sizeof(char));//strnew
	ft_bzero(list->str, (size_t)(i + 1));
	list->m = 0;
	list->p = 0;
	list->s = 0;
	list->h = 0;
	list->z = 0;
	list->w = 0;
	list->prs = 0;
	list->res = NULL;
}

char	*ft_strnchar(char *start, char *spec)
{
	int		i;
	int		k;

	i = 0;
	// if (*start && *(start + 1) == '%')
	// 	return (start);
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
				break ;
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
	char	*end;
	int		i;

	end = *start;
	*start = ft_strnchar(*start, "%sSpdDioOuUxXcC");
	i = *start - end;
	//printf("i = %d\n", i);
	if ((list = (t_flist *)malloc(sizeof(t_flist))) == NULL)
		return ;
	ft_list_zero(list, i);
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
//	printf("123:%-d 456:%+d -789:%-d 951:%0d 753:%0+d 654:%+0d 852:%10.7d 258:% 5d 321:%    .8d\n", 123, 456, -789, 951, 753, 654, 852, 258, 321);
	//printf("123:%-+0#  l 110d| 456:%-10d|\n", 123, -456);
//	printf("%012.3b%%\n");
	ft_printf("asas%bbbbbbd", 10);
//	printf("%c%c%c%c%c%c%c", 209, 133, 209, 131, 208, 185, 10);

	return (0);
}
