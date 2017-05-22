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

void	ft_error(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}

void	write_read(t_read **read, char *line)
{
	t_read	*list;

	if (!(list = (t_read *)malloc(sizeof(t_read))))
		ft_error("1\n");
	list->line = NULL;
	list->nxt = NULL;
	list->line = ft_strdup(line);
	list->nxt = *read;
}

void	read_nub_ant(t_output *otp, char *line)
{
	int		i;
	int		numb;

	i = -1;
	numb = -1;
	while (line[++i])
	{
		numb = numb * 10 + (line[i] - '0');
		if (numb > 2147483647 || numb < -214783648)
			ft_error("num 2147483647 ..\n");
	}
	if (line[i])
		ft_error("no numb ants, only links\n");
	otp->ants = numb;
}

void	find_numb_ants(t_read **read, t_output *otp)
{
	char	*line;

	line = NULL;
	while (!otp->ants && get_next_line(0, &line))
	{
		if (!line)
			ft_error("no line\n");
		else if (line[0] == '#')
		{
			if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
				ft_error("no numb ants before command\n");
		}
		else
		{
			if (ft_isalpha(line[0]))
				ft_error("no numb before\n");
			read_nub_ant(otp, line);
		}
		write_read(read, line);
		ft_strdel(&line);
	}
}

int		main(void)
{
	t_read		*read;
	t_output	*out;

	if (!(read = (t_read *)ft_memalloc(sizeof(t_read))))
		return (0);
	if (!(out = (t_output *)ft_memalloc(sizeof(t_output))))
		return (0);
	find_numb_ants(&read, out);
	find_rooms(&read, out);
	return (1);
}
