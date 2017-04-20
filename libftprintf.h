/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:25:33 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/06 16:25:33 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

/*
**		g_sr        diDsSpoOxXcCuU
**		g_count_pres  якщо є g_pres - 1, інше  - 0. Для width
**		g_res       res = кількість виведених символів
**		*str        рядок з флагами, необроблений
**		m           -
**		p           +
**		s           space
**		hs          #
**		zo          0
**		w           width
**		d           .
**		prs         precision
**		*res        рядок з обробленими флагами
*/

char				g_sr;
int					g_width;
int					g_pres;
int					g_count_pres;
int					g_count_arg;
int					g_res;

typedef struct		s_flist
{
	char			*str;
	int				m;
	int				p;
	int				s;
	int				hs;
	int				zo;
	int				w;
	int				d;
	int				prs;
	char			*res;
	int				h;
	int				hh;
	int				j;
	int				l;
	int				ll;
	int				z;
}					t_flist;

void		conv_wstr(t_flist *list, wchar_t *arg);
void		f(intmax_t value, int base, char *s, int *i);
int			ft_atoi_wl(t_flist *list, int *i);
char		*ft_conw_char(wchar_t arg);
void		ft_delete_g_varib(t_flist *list);
void		ft_init_flags(t_flist *list, char *tmp, int i);
char		*ft_itoa_base(intmax_t value, int base);
void		ft_just_do_it(char **start, va_list *ap);
void		ft_list_lh(t_flist *list);
void		ft_list_zero(t_flist *list, int i);
void		ft_put_len_space(int len, char s);
void		ft_put_nbr(intmax_t nb);
void		ft_put_unbr(uintmax_t nb);
void		ft_putnchar(char c);
void		ft_putnstr(char const *s, int len);
void		ft_putstr(char const *s);
void		ft_realise(const char *format, va_list *ap);
void 		ft_rest(t_flist *list);
void		ft_s_n(t_flist *list);
void		ft_sign(t_flist *list, intmax_t number, int len_arg, int pres);
void		ft_sign_o(t_flist *list, int len_arg, int pres, uintmax_t number);
void		ft_sign_s(t_flist *list, int len_arg);
void		ft_sign_u(t_flist *list, int len_arg, int pres);
void		ft_sign_x(t_flist *list, int len_arg, int pres, uintmax_t number);
intmax_t	ft_signed_size(t_flist *list, va_list *ap);
void		ft_spec_c_C(t_flist *list, va_list *ap);
intmax_t	ft_spec_D(va_list *ap);
void		ft_spec_d_i(t_flist *list, va_list *ap);
uintmax_t	ft_spec_O(va_list *ap);
void		ft_spec_o_O_x_X(t_flist *list, va_list *ap);
void		ft_spec_s_S(t_flist *list, va_list *ap);
void		ft_spec_u_U(t_flist *list, va_list *ap);
void		ft_spec_x_X(t_flist *list, va_list *ap);
char		*ft_strnchar(char *start, char *spec);
char		*ft_strnchar_for_else_flag(char *start, char *spec);
char		*ft_uitoa_base(uintmax_t value, int base);
uintmax_t	ft_unsigned_size(t_flist *list, va_list *ap);
void		ft_wid_len(t_flist *list);
void		ft_write_number_d_i(t_flist *list, intmax_t number, int len_arg);
void		ft_write_number_o(t_flist *list, int len_arg, uintmax_t number);
void		ft_write_number_s(t_flist *list, int len_arg, int pres, int k);
void		ft_write_number_u(t_flist *list, uintmax_t number, int len_arg);
void		ft_write_number_x(t_flist *list, int len_arg, uintmax_t number);
void		fu(uintmax_t value, int base, char *s, int *i);
int 		leng_wchar(wchar_t arg);
void		wsrt(t_flist *list, wchar_t *arg);
int			ft_printf(const char *format, ...);

#endif
