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

// # define DEC_BASE "0123456789"
// # define OCT_BASE "01234567"
// # define BIN_BASE "01"
// # define HEX_BASE "0123456789abcdef"
// # define HEXL_BASE "0123456789ABCDEF"
// # define MIN(a, b) (a < b ? a : b)

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

char				g_spec;
int					g_width;
int					g_pres;

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

int					main(void);
int					ft_printf(const char *format, ...);
int					ft_realise(const char *format, va_list *ap, int i);

#endif
