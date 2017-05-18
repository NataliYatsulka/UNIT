/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:26:30 by nyatsulk          #+#    #+#             */
/*   Updated: 2016/12/02 13:28:56 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# define BUFF_SIZE 10

/*
** printf
*/

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

/*
** libft
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** gnl
*/

typedef struct		s_list_1
{
	char			*str;
	int				f_d;
	struct s_list_1	*nex;
	char			*p;
	char			*t;
	char			*cut;
}					t_list_1;

/*
** libft
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					ft_nb_split_word(char const *s, char c);
char				*ft_itoa(int n);
int					ft_nb_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** printf
*/

void				conv_wstr(t_flist *list, wchar_t *arg);
void				f(intmax_t value, int base, char *s, int *i);
int					ft_atoi_wl(t_flist *list, int *i);
char				*ft_conw_char(wchar_t arg);
void				ft_delete_g_varib(t_flist *list);
void				ft_init_flags(t_flist *list, char *tmp, int i);
char				*ft_itoa_base(intmax_t value, int base);
void				ft_just_do_it(char **start, va_list *ap);
void				ft_list_lh(t_flist *list);
void				ft_list_zero(t_flist *list, int i);
void				ft_put_len_space(int len, char s);
void				ft_put_nbr(intmax_t nb);
void				ft_put_unbr(uintmax_t nb);
void				ft_putnchar(char c);
void				ft_putnstr(char const *s, int len);
void				ft_putstr(char const *s);
void				ft_realise(const char *format, va_list *ap);
void				ft_rest(t_flist *list);
void				ft_s_n(t_flist *list);
void				ft_sign(t_flist *list, intmax_t number, int len_arg,
					int pres);
void				ft_sign_o(t_flist *list, int len_arg, int pres,
					uintmax_t number);
void				ft_sign_s(t_flist *list, int len_arg);
void				ft_sign_u(t_flist *list, int len_arg, int pres);
void				ft_sign_x(t_flist *list, int len_arg, int pres,
					uintmax_t number);
intmax_t			ft_signed_size(t_flist *list, va_list *ap);
void				ft_spec_c_c(t_flist *list, va_list *ap);
intmax_t			ft_spec_d(va_list *ap);
void				ft_spec_d_i(t_flist *list, va_list *ap);
uintmax_t			ft_spec_o(va_list *ap);
void				ft_spec_o_o_x_x(t_flist *list, va_list *ap);
void				ft_spec_s_s(t_flist *list, va_list *ap);
void				ft_spec_u_u(t_flist *list, va_list *ap);
void				ft_spec_x_x(t_flist *list, va_list *ap);
char				*ft_strnchar(char *start, char *spec);
char				*ft_strnchar_for_else_flag(char *start, char *spec);
char				*ft_uitoa_base(uintmax_t value, int base);
uintmax_t			ft_unsigned_size(t_flist *list, va_list *ap);
void				ft_wid_len(t_flist *list);
void				ft_write_number_d_i(t_flist *list, intmax_t number,
					int len_arg);
void				ft_write_number_o(t_flist *list, int len_arg,
					uintmax_t number);
void				ft_write_number_s(t_flist *list, int len_arg, int pres,
					int k);
void				ft_write_number_u(t_flist *list, uintmax_t number,
					int len_arg);
void				ft_write_number_x(t_flist *list, int len_arg,
					uintmax_t number);
void				fu(uintmax_t value, int base, char *s, int *i);
int					leng_wchar(wchar_t arg);
void				wsrt(t_flist *list, wchar_t *arg);
int					ft_printf(const char *format, ...);
void				ft_choose(t_flist *list, va_list *ap);
void				ft_put_count_char(char c);
void				ft_put_count_str(char const *s);

/*
** gnl
*/

int					get_next_line(const int fd, char **line);

/*
** added func
*/

void				malloc_for_two_mas(char **s, int x, int y);

#endif
