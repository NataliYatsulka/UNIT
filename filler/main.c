/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:45:06 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/25 16:45:06 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char		*line;
	t_filler	*f;

	line = NULL;
	f = (t_filler *)ft_memalloc(sizeof(t_filler));
	printf("1\n");
	get_next_line(0, &line);
	// printf("gnl-RETURN=%d\n", get_next_line(0, &line));
	printf("2\n");
	if (ft_strnequ(line, "$$$ exec p1", 11))
		f->sgn = '0';
	else
		f->sgn = 'X';
	printf("line =|%s|  f_sgn =|%c|\n", line, f->sgn);
	ft_strdel(&line);
	return (0);
}
