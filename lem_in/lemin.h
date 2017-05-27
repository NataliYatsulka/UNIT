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
**	x, y - coordinates near the name of room
**	next
**	nmb - порядковий номер
**	name - name room
*/

typedef struct		s_room
{
	char			*name;
	int				numb;
	int				x;
	int				y;
	struct s_room	*next;
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
	
	int				number_room_start;
	int				number_room_end;
	struct s_room	*room;

	char	*test;
	int		test1;
	int		test2;
	// char			*start;??
	// int				x_start;
	// int				y_start;
	// char			*end;??
	// int				x_end;
	// int				y_end;

}					t_output;

int					main(void);

#endif
