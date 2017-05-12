/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:54:51 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/25 15:54:52 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# define R(a, b) ((a >= b) ? a : b)

/*
**	x,y  - coord tokena 
*/

typedef struct 	s_filler
{
	char		sgn;
	int			len_map_x;
	int			len_map_y;
	int			t_x;
	int			t_y;
	char		**tkn;
	char		**map;
	int			**distmap;
	int			enem_x;
	int			enem_y;
	int			x_return;
	int			y_return;
}				t_filler;

int				main(void);

#endif
