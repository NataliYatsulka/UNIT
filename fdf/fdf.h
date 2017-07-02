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
# include "mlx.h"
# include <math.h>

typedef struct		s_readfdf
{
	char			**arr;
}					t_readfdf;

typedef struct		s_cofdf
{
	int				x;
	int				y;
	int				z;
}					t_cofdf;

typedef struct		s_fdf
{
	char			*av;
	char			**map;
	char			*line;
	int				num_map_row;
	int				fd;
}					t_fdf;

int			main(int ac, char **av);

#endif