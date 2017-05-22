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

/*
**	line - gnl read
**	nxt - next
*/

typedef struct		s_read
{
	char			*line;
	struct s_read	*nxt;
}					t_read;

/*
**	x_room y_room - coordinates near the name of room
**	n - next
**
*/

typedef struct		s_room
{
	char			*name_room;
	int				numb_room;
	int				x_room;
	int				y_room;
	struct s_room	*n;
}					t_room;

/*
**	sgn - 
*/

typedef struct		s_link
{
	char			sgn;
}					t_link;

/*
**	ants - numb in start
**
*/

typedef struct		s_output
{
	int				ants;
	int				count_start;
	int				count_end;
	char			*start;
	// int				x_start;
	// int				y_start;
	char			*end;
	// int				x_end;
	// int				y_end;

}					t_output;

int					main(void);

#endif
