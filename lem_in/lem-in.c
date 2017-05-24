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

/////////////////delete in end project
char				g_sr;
int					g_width;
int					g_pres;
int					g_count_pres;
int					g_count_arg;
int					g_res;
///////////////////////////////
#include "lemin.h"

void	ft_error(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}

// void	delete_struct(t_read **read, t_output **out)
// {

// }

void 	write_input_on_console(t_read *read)
{
	while (read)
	{
		printf("%s\n", read->line);
		read = read->nxt;
	}
}

void	write_read(t_read **read, char *line)
{
	t_read	*list;
	t_read	*ptr;

	ptr = *read;
	if (!(list = (t_read *)malloc(sizeof(t_read))))
		ft_error("1\n");
	while (ptr->nxt)
	{
		ptr = ptr->nxt;
	}
	ptr->nxt = list;
	list->nxt = NULL;
	list->line = ft_strdup(line);
}

////////////////////
///////////////////
////////////////////
int		check_not_links(char *line)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
		return (1);
	while (line[++i])
	{
		if (line[i] == ' ')
			count++;
	}
	if (count == 2)
		return (1);
	return (0);
}

int		room_name(t_output *otp, char *line1)
{
	int		i;

	i = -1;
	if (otp->room->name)
		ft_error("start two time");
	while (line1[++i] && !otp->room->name)
	{
		if (line1[i] == ' ')
		{
			otp->room->name = ft_strsub(line1, 0, i);
			break ;
		}
		if (line1[i] == '-')
			ft_error("bad name room, no - at the name");
	}
	return (i);
}

/*
**	перевірка наступного рядка після команди start
*/

void	put_coord_start(t_output *otp, char *line1)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (check_not_links(line1) && line1[0] != ' ')
		j = room_name(otp, line1);
	else
		ft_error("no valid name");
	if (line1[j] == ' ' && line1[j + 1])
	{

		j++;
	}
	else
		ft_error("no coord 1");
	if (line1[j] == ' ' && line1[j + 1])
	{
		
		j++;
	}
	else
		ft_error("no coord 2");


}

void	check_s_e_command(t_read **read, t_output *otp, char *line)
{
	// int		i;
	char	*line1;

	// i = 0;
	line1 = NULL;
	// while (line[i])
	// {
		if (ft_strequ(line, "##start"))
		{
			if (otp->number_room_start > -1)
				ft_error("more than one start");
			write_read(read, line);
			get_next_line(0, &line1);
			if (line1[0] == '#')
				ft_error("command after start");
			put_coord_start(otp, line1);
			write_read(read, line1);
			ft_strdel(&line1);
		}
		else if (ft_strequ(line, "##end"))
		{
			
		}		
	// }
}

void	find_rooms(t_read **read, t_output *otp)
{
	char	*line;

	line = NULL;
	otp->number_room_start = -1;
	while (get_next_line(0, &line) && check_not_links(line))
	{
		if (line[0] == '#' && line[1] == '#')
		{
			check_s_e_command(read, otp, line);
			write_read(read, line);
		}
		else if (line[0] == '#')
			write_read(read, line);
		else
		{
			// check_on_space(otp, line);
			// put_room_numb(otp);
			write_read(read, line);
		}
		ft_strdel(&line);
	}
	// if (!line)
	// 	ft_error("no line");
}

/*//////////////////////////////////////////////////////////////////////////////
**			find numb ants
*///////////////////////////////////////////////////////////////////////////////

void	read_nub_ant(t_output *otp, char *line)
{
	int		i;
	int		numb;

	i = -1;
	numb = 0;
	if (!ft_isdigit(line[0]))
		ft_error("some error");
	while (line[++i])
	{
		if (line[i] && ft_isdigit(line[i]))
		{	
			numb = numb * 10 + (line[i] - '0');
			if (numb > 2147483647 || numb < -214783648)
				ft_error("num 2147483647 ..\n");
		}
		else
			ft_error("bad input, something else in input after digits");
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
	// if (!line)
	// 	ft_error("no line");
}

int		main(void)
{
	t_read		*read;
	t_output	*out;
	t_room		*room;
	t_read		*tmp;

	if (!(read = (t_read *)ft_memalloc(sizeof(t_read))))
		return (-1);
	if (!(out = (t_output *)ft_memalloc(sizeof(t_output))))
		return (-1);
	if (!(room = (t_room *)ft_memalloc(sizeof(t_room))))
		return (-1);
	find_numb_ants(&read, out);

	tmp = read;
	read = read->nxt;
	ft_strdel((char **)&tmp);
	find_rooms(&read, out);//, out);

	write_input_on_console(read);
	// delete_struct(&read, &out);
	return (1);
}
