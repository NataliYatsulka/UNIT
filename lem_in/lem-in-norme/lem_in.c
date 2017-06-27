/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:29:57 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/06/27 18:29:58 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	read_nub_ant(t_output *otp, char *line)
{
	int					i;
	long long int		numb;

	i = -1;
	numb = 0;
	if (!ft_isdigit(line[0]))
		ft_error("no ants\n");
	while (line[++i])
	{
		if (line[i] && ft_isdigit(line[i]))
		{
			numb = numb * 10 + (line[i] - '0');
			if (numb > 2147483647 || numb < -2147483648)
				ft_error("num 2147483647 ..\n");
		}
		else
			ft_error("bad input or something else in input after digits\n");
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

void	init_struct(t_output *otp)
{
	otp->room = NULL;
	otp->link = NULL;
	otp->ants = 0;
	otp->num_rooms = 0;
}

int		main(void)
{
	t_read		*read;
	t_output	out;
	t_room		*tmp;

	read = NULL;
	init_struct(&out);
	find_numb_ants(&read, &out);
	find_rooms(&read, &out);
	write_input_on_console(read);
	tmp = out.room;
	while (tmp->next)
		tmp = tmp->next;
	out.num_rooms = tmp->numb + 1;
	if (!(out.tmp = (int *)ft_memalloc(sizeof(int) * (out.num_rooms + 1))))
		ft_error("malloc5\n");
	if (out.arr[out.number_room_start][out.number_room_end] == 1)
		print_ants_way(&out);
	else
	{
		func_set(&out, out.number_room_start, 5);
		algo_lemin(&out, out.number_room_start, 0);
		func_set(&out, out.number_room_start, 1);
		find_best_way(&out);
	}
	return (1);
}
