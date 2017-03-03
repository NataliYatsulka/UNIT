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

typedef struct		s_flist
{
	char			*str;//рядок з флагами, необроблений
	int				m;//-
	int				p;//+
	int				s;//space
	int				h;//#
	int				z;//0
	int				w;//width
	int				prs;//precision
//	struct t_flist	*n;
	int				*tmp;//масив 1 0 (флаги mpshz)
	char			*res;//рядок з обробленими флагами
}					t_flist;

int					main(void);
int					ft_printf(const char *format, ...);
int					ft_realise(const char *format, va_list *ap, int i);

#endif
