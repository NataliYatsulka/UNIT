/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 19:19:47 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/05/17 19:19:47 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"

typedef struct		s_read
{
	char			*line;
	struct s_read	*n;
}					t_read;

typedef struct		s_room
{
	char			*name_room;
	int				numb_room;
	int				x_room;
	int				y_room;
	struct s_room	*n;
}					t_room;

typedef struct		s_link
{
	char			sgn;
}					t_link;

typedef struct		s_output
{
	int				ants;
	struct s_read
}					t_output;

int					main(void);

#endif
