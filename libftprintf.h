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

char				g_sr;// diDsSpoOxXcCuU
int					g_width;
int					g_pres;
int					g_count_pres;// якщо є g_pres - 1, інше  - 0. Для width
int					g_count_arg;
int					g_res;//res = кількість виведених символів

typedef struct		s_flist
{
	char			*str;//рядок з флагами, необроблений
	int				m;//-
	int				p;//+
	int				s;//space
	int				hs;//#
	int				zo;//0
	int				w;//width
	int				d;// .
	int				prs;//precision
	char			*res;//рядок з обробленими флагами
	int				h;
	int				hh;
	int				j;
	int				l;
	int				ll;
	int				z;
}					t_flist;

int		ft_printf(const char *format, ...);

#endif
