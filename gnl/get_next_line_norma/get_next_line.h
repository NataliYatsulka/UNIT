/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:54:11 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/01/17 16:54:12 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_list_1
{
	char			*str;
	int				f_d;
	struct s_list_1	*nex;
	char			*p;
	char			*t;
	char			*cut;
}					t_list_1;

# define BUFF_SIZE 10

int					get_next_line(const int fd, char **line);

#endif
