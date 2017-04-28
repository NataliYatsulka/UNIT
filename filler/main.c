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

void	read_numb_max_xy(t_filler *f, char *line)
{
	int		j;

	j = 0;
	//printf("%s\n", &line);
	while ((*line) && (*line) < 48 && (*line) > 57)
		j++;

	//return (*i);
}

void	read_plato(t_filler *f, char *line)
{
	int		i;

	i = 0;
	if (!f->len_map_x || !f->len_map_y)
	{
		read_numb_max_xy(f, line);
	}
}

// все нулями робить ft_memaloc
// void	list_f_zero(void)
// {
// 	f->sgn = 'X';
// 	f->len_map_x = 0;
// 	f->len_map_y = 0;
// 	return (f);
// }

int		main(void)
{
	char		*line;
	t_filler	*f;

	line = NULL;
	if (!(f = (t_filler *)ft_memalloc(sizeof(t_filler))))
		return (1);
	f->sgn = 'X';
	get_next_line(0, &line);
	if (ft_strnequ(line, "$$$ exec p1", 11))
		f->sgn = 'O';
	ft_strdel(&line);
	while (get_next_line(0, &line))
	{
		read_plato(f, line);
		write(1, "end", 3);
		return (0);
	}
	ft_strdel(&line);
	printf("end of program\n");
	return (0);
}
