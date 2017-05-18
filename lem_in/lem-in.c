/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:49:45 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/05/15 16:49:45 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	write_output(t_read **read, *line)
{
	t_read	*read1;

	read1 = ()
}

void	find_numb_ants(t_read **read, t_output *otp)
{
	char	*line;

	line = NULL;
	while (!otp->ants && get_next_line(0, &line))
	{
		if (!line)
			ft_error();
		else if (line[0] == '#')
		{
			if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
				ft_error();
			write_output(read, line);

		}
		ft_strdel(&line);
	}
}

int		main(void)
{
	// char		*line;
	t_read		*r;
	t_output	*o;

	if (!(r = (t_read *)ft_memalloc(sizeof(t_read))))
		return (1);
	if (!(o = (t_output *)ft_memalloc(sizeof(t_output))))
		return (1);
	find_numb_ants(&r, o);
	return (0);
}
