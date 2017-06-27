/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:29:48 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/06/27 18:29:49 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	put_coord_end(t_output *otp, char *line1)
{
	int		j;

	j = 0;
	if (check_not_links(line1) && line1[0] != ' ' && line1[0] != 'L')
		j = room_name_end(otp, line1);
	else
		ft_error("no valid name_end\n");
	if (line1[j] == ' ' && line1[j + 1])
		j = valid_numb(line1, j);
	else
		ft_error("no coord 1 end\n");
	if (line1[j] == ' ' && line1[j + 1])
		j = valid_numb(line1, j);
	else
		ft_error("no coord 2 end\n");
	if (line1[j] != 0)
		ft_error("smth after second coord in room block end\n");
}

void	check_s_e_command_2(t_read **read, t_output *otp, char *line1)
{
	put_coord_end(otp, line1);
	write_read(read, line1);
}

void	check_s_e_command(t_read **read, t_output *otp, char *line)
{
	char	*line1;

	line1 = NULL;
	if (ft_strequ(line, "##start"))
	{
		if (otp->number_room_start > -1)
			ft_error("more than one start\n");
		write_read(read, line);
		get_next_line(0, &line1);
		if (line1[0] == '#')
			ft_error("command after start\n");
		put_coord_start(otp, line1);
		write_read(read, line1);
	}
	else if (ft_strequ(line, "##end"))
	{
		if (otp->number_room_end > -1)
			ft_error("more than one end\n");
		write_read(read, line);
		get_next_line(0, &line1);
		if (line1[0] == '#')
			ft_error("command after end\n");
		check_s_e_command_2(read, otp, line1);
	}
	ft_strdel(&line1);
}

void	put_good_room(t_output *otp, char *line)
{
	int		j;

	j = 0;
	if (check_not_links(line) && line[0] != ' ' && line[0] != 'L')
		j = room_name(otp, line);
	else
		ft_error("no valid name\n");
	if (line[j] == ' ' && line[j + 1])
		j = valid_numb(line, j);
	else
		ft_error("no first coord\n");
	if (line[j] == ' ' && line[j + 1])
		j = valid_numb(line, j);
	else
		ft_error("no second coord\n");
	if (line[j] != 0)
		ft_error("smth after second coord in room block\n");
}

void	find_rooms(t_read **read, t_output *otp)
{
	char	*line;

	line = NULL;
	otp->number_room_start = -1;
	otp->number_room_end = -1;
	while (get_next_line(0, &line) && (line[0] == '#' || check_not_links(line)))
	{
		if (line[0] == '#' && line[1] == '#')
		{
			if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
				check_s_e_command(read, otp, line);
			else
				write_read(read, line);
		}
		else if (line[0] == '#')
			write_read(read, line);
		else if (check_not_links(line))
		{
			put_good_room(otp, line);
			write_read(read, line);
		}
		ft_strdel(&line);
	}
	find_links(read, otp, line);
	ft_strdel(&line);
}
