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

/*
**	delete
*/
int		check_not_links(char *line);


/////////////
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
	t_read	*ptr;

	ptr = *read;
	while (ptr->nxt)
		ptr = ptr->nxt;
	ptr->line = ft_strdup(line);
	ptr->nxt = (t_read *)malloc(sizeof(t_read));
	ptr->nxt->line = NULL;
	ptr->nxt->nxt = NULL;
}

////////////////////

void	read_name_links(t_read *read, t_output *otp, char *line)
{
	write_read(&read, line);
	otp->test = NULL;
}

int		check_links(char *line)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (line[++i])
	{
		if (line[i] == '-')
			count++;
	}
	if (count == 2)
		return (1);
	return (0);
}

void	find_links(t_read **read, t_output *otp, char *line)
{
	if (line == NULL)
		ft_error("emty line. no links");
	if (otp->number_room_start < 0 || otp->number_room_end < 0)
		ft_error("no end or start");
	if (otp->room->numb < 2)
		ft_error("no rooms between start - end");
	if (line != NULL)
		if (check_not_links(line) < 1 && check_links(line))
			read_name_links(*read, otp, line);

}

/*
**	block ROOM
*/

int		check_not_links(char *line)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (line[++i])
	{
		if (line[i] == ' ')
			count++;
	}
	if (count == 2)
		return (1);
	return (0);
}

void	create_name_room(t_output *otp)
{
	t_room	*tmp;

	tmp = otp->room;
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = (t_room *)malloc(sizeof(t_room))))
		return ;
	tmp->next->name = NULL;
	//виправити для проходження по-порядку tmp->next->numb
	tmp->next->numb = 0;
	tmp->next->x = 0;
	tmp->next->y = 0;
}

int		room_name(t_output *otp, char *line1)
{
	int		i;

	i = -1;
	create_name_room(otp);
	while (line1[++i] && !otp->room->name)
	{
		if (line1[i] == ' ')
		{
			otp->room->name = ft_strsub(line1, 0, i);
			break ;
		}
		if (line1[i] == '-')
			ft_error("1bad room name, no '-' at the name1\n");
	}
	return (i);
}

int		room_name_start(t_output *otp, char *line1)
{
	int		i;

	i = -1;
	create_name_room(otp);
	if (otp->number_room_start > -1)
		ft_error("start two times\n");
	while (line1[++i] && !otp->room->name)
	{
		if (line1[i] == ' ')
		{
			otp->room->name = ft_strsub(line1, 0, i);
			otp->number_room_start = otp->room->numb;
			otp->room->numb++;
			break ;
		}
		if (line1[i] == '-')
			ft_error("2bad room name, no '-' at the name2\n");
	}
	return (i);
}

int		room_name_end(t_output *otp, char *line1)
{
	int		i;

	i = -1;
	create_name_room(otp);
	if (otp->number_room_end > -1)
		ft_error("end two times\n");
	while (line1[++i] && !otp->room->name)
	{
		if (line1[i] == ' ')
		{
			otp->room->name = ft_strsub(line1, 0, i);
			otp->number_room_end = otp->room->numb;
			otp->room->numb++;
			break ;
		}
		if (line1[i] == '-')
			ft_error("3bad room name, no '-' at the name3\n");
	}
	return (i);
}

/*
**	перевірка наступного рядка після команди start
*/

int		valid_numb(char *line, int i)
{
	i++;
	while (line[i] && (line[i] != ' '))// || line[i + 1] != '\0'))
	{
		if (ft_isdigit(line[i]))
			i++;
		else
			ft_error("error-in-coord\n");
	}
	return (i);
}

void	put_coord_start(t_output *otp, char *line1)
{
	int		j;

	j = 0;
	if (check_not_links(line1) && line1[0] != ' ')
		j = room_name_start(otp, line1);
	else
		ft_error("no valid name_start\n");
	if (line1[j] == ' ' && line1[j + 1])
		j = valid_numb(line1, j);
	else
		ft_error("no coord 1_start\n");
	if (line1[j] == ' ' && line1[j + 1])
		j = valid_numb(line1, j);
	else
		ft_error("no coord 2_start\n");
	if (line1[j] != 0)
		ft_error("smth after second coord in room block start\n");
}

void	put_coord_end(t_output *otp, char *line1)
{
	int		j;

	j = 0;
	if (check_not_links(line1) && line1[0] != ' ')
		j = room_name_end(otp, line1);//виправити для end???? //delete after do this func
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
		put_coord_end(otp, line1);
		write_read(read, line1);
	}
	ft_strdel(&line1);
}

void	put_good_room(t_output *otp, char *line)
{
	int		j;

	j = 0;
	if (check_not_links(line) && line[0] != ' ')
		j = room_name(otp, line);//виправити для всіх інших запис в структуру???? //delete after do this func
	else
		ft_error("no valid name\n");
	if (line[j] == ' ' && line[j + 1])
		j = valid_numb(line, j);
	else
		ft_error("no coord 1 ...\n");
	if (line[j] == ' ' && line[j + 1])
		j = valid_numb(line, j);
	else
		ft_error("no coord 2 ...\n");
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
	// if (line == NULL)
	// 	ft_error("emty line. no links");
	// if (otp->number_room_start < 0 || otp->number_room_end < 0)
	// 	ft_error("no end or start");
	// if (otp->room->numb < 2)
	// 	ft_error("no rooms between start - end");
	// if (line != NULL)
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
		ft_error("some error\n");
	while (line[++i])
	{
		if (line[i] && ft_isdigit(line[i]))
		{
			numb = numb * 10 + (line[i] - '0');
			if (numb > 2147483647 || numb < -214783648)
				ft_error("num 2147483647 ..\n");
		}
		else
			ft_error("bad input, something else in input after digits\n");
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

// void	init_struct(t_output **out)
// {
// 	if (!(*out = (t_output *)malloc(sizeof(t_output))))
// 		ft_error("malloc 1");
// 	(*out)->room = NULL;
// }

int		main(void)
{
	t_read		*read;
	t_output	*out;
	// t_room		*room;
	// t_read		*tmp;

	// init_struct(&out);
	if (!(read = (t_read *)malloc(sizeof(t_read))))
		return (-1);
	read->line = NULL;
	read->nxt = NULL;
	if (!(out = (t_output *)malloc(sizeof(t_output))))
		return (-1);
	if (!(out->room = (t_room *)malloc(sizeof(t_room))))
		return (-1);
	out->room->name = NULL;
	out->room->numb = 0;
	out->room->x = 0;
	out->room->y = 0;
	out->room->next = NULL;

	find_numb_ants(&read, out);
	// tmp = read;
	// read = read->nxt;
	// ft_strdel((char **)&tmp);
	find_rooms(&read, out);//, out);

	write_input_on_console(read);
	// delete_struct(&read, &out);
	while (1);
	return (1);
}
