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

typedef struct 	s_filler
{
	char		sgn;
	int			len_map_x;
	int			len_map_y;
	int			xx;
	int			xy;
	int			ox;
	int			oy;
	int			t_x;
	int			t_y;
	char		**tkn;
	char		**map;
}				t_filler;

int				main(void);

#endif