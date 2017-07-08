/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 21:24:41 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/06/30 21:24:41 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
//# include "mlx.h"
# include <math.h>

// typedef struct		s_readfdf
// {
// 	char			**arr;
// }					t_readfdf;

typedef struct		s_cfdf
{
	float				x;
	float				y;
	float				z;
}					t_cfdf;

typedef struct		s_fdf
{
	t_cfdf			**arr_coord;
	t_cfdf			**arr_for_degree;
	char			*av;
	char			**map;
	char			*line;
	int				num_map_row;
	int				num_map_col;
	int				fd;
}					t_fdf;

int			main(int ac, char **av);

#endif
