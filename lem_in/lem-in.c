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

void 	write_input_on_console(t_read *read)
{
	while (read)
	{
		ft_printf("%s\n", read->line);
		read = read->nxt;
	}
	ft_printf("\n");
}

void	write_read(t_read **read, char *line)
{
	t_read	*ptr;

	ptr = *read;
	if (ptr)
	{
		while (ptr->nxt)
			ptr = ptr->nxt;
		ptr->nxt = (t_read *)ft_memalloc(sizeof(t_read));
		ptr->nxt->line = ft_strdup(line);
	}
	else
	{
		*read = (t_read *)ft_memalloc(sizeof(t_read));
		(*read)->line = ft_strdup(line);
	}
}

///////////////////////////////////////////////////
/*
**	write ants
*/
///////////////////////////////////////////////////

void	print_ants_way(t_output *otp)
{
	int		i;
	t_room	*ptr;

	ptr = otp->room;
	while (ptr)
	{
		if (ptr->numb == otp->number_room_end)
			break;
		ptr = ptr->next;
	}
	i = 1;
	while (i <= otp->ants)
	{
		ft_printf("L%d-%s", i, ptr->name);
		(i == otp->ants) ? (ft_printf("\n")) : (ft_printf(" "));
		i++;
	}
}

////////////////////////////////////////////////////
/*
**	algorithm
*/
////////////////////////////////////////////////////

void	func_set_i(t_output *otp, int j, int k)
{
	int		l;

	l = -1;

	int	i;//delete
	int q = 0;
	int w = 0;

	t_room	*ptr;//delete
	t_room	*tmp;//delete

	ptr = otp->room;//delete
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
	}
	w = tmp->numb;
	i = -1;//delete
	while (++i < w + 1)
	{
		q = -1;
		while (++q < w + 1)
			printf("%d", otp->arr[i][q]);
		printf("\n");
	}
	while (++l < otp->num_rooms)
	{
		if (k == 5 && otp->arr[l][j] == 1)
		{
			otp->arr[l][j] = k;
			// otp->arr[j][l] = k;
		}
		else if (k == 1 && otp->arr[l][j] == 5)
		{
			otp->arr[l][j] = k;
			// otp->arr[j][l] = k;
		}
	}
	printf("\n");
}


void	func_set(t_output *otp, int j, int k)
{
	int		l;

	l = -1;

	int	i;//delete
	int q = 0;
	int w = 0;

	t_room	*ptr;//delete
	t_room	*tmp;//delete

	ptr = otp->room;//delete
	while (ptr->next)
	{
		tmp = ptr;
		ptr = ptr->next;
	}
	w = tmp->numb;
	i = -1;//delete
	while (++i < w + 1)
	{
		q = 0;
		printf("%d_", i);
		while (++q < w + 1)
			printf("%d", otp->arr[i][q]);
		printf("\n");
	}

	while (++l < otp->num_rooms)
	{
		if (k == 5 && otp->arr[l][j] == 1)
		{
			otp->arr[l][j] = k;
			// otp->arr[j][l] = k;
		}
		else if (k == 1 && otp->arr[l][j] == 5)
		{
			otp->arr[l][j] = k;
			// (*otp)->arr[j][l] = k;
		}
	}
	printf("\n");
}

void	copy_link(t_output *otp, int count)
{
	t_link	*ptr;

	if (!(otp->link))
	{
		if (!(otp->link = (t_link *)ft_memalloc(sizeof(t_link))))
			ft_error("malloc link\n");
		ptr = otp->link;
	}
	else
	{
		ptr = otp->link;
		while (ptr->next)
			ptr = ptr->next;
		if (!(ptr->next = (t_link *)malloc(sizeof(t_link))))
			ft_error("malloc link2\n");
		ptr = ptr->next;
	}
	if (!(ptr->arlink = (int *)malloc(count * sizeof(int))))
		ft_error("malloc link3\n");
	ptr->arlink = ft_memcpy(ptr->arlink, otp->tmp, count * sizeof(int));
	ptr->len = count;
}


void	algo_lemin(t_output *otp, int i, int count)
{
	int		j;

	j = 0;
	otp->tmp[count] = i;
	while (otp->arr[i][j] && j < otp->num_rooms && i < otp->num_rooms)
	{
		if (j == otp->number_room_end && otp->arr[i][j] == 1)
		{
			otp->tmp[count + 1] = j;
			copy_link(otp, count + 2);
			
		}
		else if (otp->arr[i][j] == 1)
		{
			func_set(otp, j, 5);
			algo_lemin(otp, j, count + 1);
			func_set(otp, j, 1);
		}
		j++;
	}
}

////////////////////////////////////////////////////
/*
**	block LINKS
*/
/////////////////////////////////////////////////////

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
	if (count == 1)
		return (1);
	return (0);
}

void	matrix_for_links(t_output *otp)
{
	int		m;
	int		j;
	int		k;
	t_room	*ptr;

	ptr = otp->room;
	k = 0;
	while (ptr->next)
	{
		k++;
		ptr = ptr->next;
	}
	j = -1;
	if (!(otp->arr = (int **)malloc((k + 1) * sizeof(int *))))
		ft_error("malloc for arrs");
	otp->arr[k + 1] = NULL;
	while (++j < k + 1)
		if (!(otp->arr[j] = (int *)malloc((k + 1) * sizeof(int))))
			ft_error("malloc for arrs11");
	j = -1;
	while (++j < k + 1)
	{
		m = -1;
		while (++m < k + 1)
			otp->arr[j][m] = 7;
	}
}

int		get_numb_room_for_link(t_output *otp, char *s)
{
	t_room	*ptr;

	ptr = otp->room;
	while (ptr)
	{
		if (ft_strequ(ptr->name, s))
			return (ptr->numb);
		ptr = ptr->next;
	}
	ft_error("no link with this name\n");
	return (0);
}

void	write_in_struct_links(t_output *otp, char *line)
{
	int		i;
	int		j;
	int		k;
	char	**arr_name_link;

	k = 0;
	arr_name_link = ft_strsplit(line, '-');
	while (arr_name_link[k])
		k++;
	if (k != 2)
		ft_error("no 2 link in line\n");
	i = get_numb_room_for_link(otp, arr_name_link[0]);
	j = get_numb_room_for_link(otp, arr_name_link[1]);
	if (i != j)
	{
		otp->arr[i][j] = 1;
		otp->arr[j][i] = 1;
	}
	ft_strdel(arr_name_link);
}

void	read_name_links(t_read *read, t_output *otp)//, char *line)
{
	int	k = 0;int i,j;//delete
	char	*line1;
	// t_link	*link;
	t_room	*ptr;//delete
	t_room	*tmp;//delete

	ptr = otp->room;//delete
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
	}
	k = tmp->numb;
	//delete
	// if (!(link = (t_link *)malloc(sizeof(t_link))))
	// 	return ;
	// line1 = NULL;//maybe delete?????????
	// matrix_for_links(otp);
	// write_in_struct_links(otp, line);
	// write_read(&read, line);
	while (get_next_line(0, &line1))
	{
		if (line1[0] == '#' && line1[1] == '#')
		{
			if (ft_strequ(line1, "##start") || ft_strequ(line1, "##end"))
				ft_error("##start or ##end in block links");
			else
				write_read(&read, line1);
		}
		else if (line1[0] == '#')
			write_read(&read, line1);
		else
		{
			if (*line1 == '\0')
				break ;
			write_in_struct_links(otp, line1);
			write_read(&read, line1);
		}
		ft_strdel(&line1);
	}
	i = -1;//delete
	while (++i < k + 1)
	{
		j = -1;
		while (++j < k + 1)
			printf("%d", otp->arr[i][j]);
		printf("\n");
	}
}

void	find_links(t_read **read, t_output *otp, char *line)
{
	if (line == NULL)
		ft_error("empty line. no links");
	if (otp->number_room_start < 0 || otp->number_room_end < 0)
		ft_error("no end or start in block room");
	if (line != NULL)
	{
		if (check_links(line))
		{
			matrix_for_links(otp);
			write_in_struct_links(otp, line);
			write_read(read, line);
			read_name_links(*read, otp);//, line);§
		}
		else
			ft_error("smth went wrong in func find_links");
	}
}

//////////////////////////////////////////////////////
/*
**	block ROOM
*/
//////////////////////////////////////////////////////

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
	int		num;

	num = 0;
	tmp = otp->room;
	if (tmp)
	{
		while (tmp->next)
		{
			num++;
			tmp = tmp->next;
		}
		if (!(tmp->next = (t_room *)ft_memalloc(sizeof(t_room))))
			return ;
		tmp->next->numb = num + 1;
	}
	else
		otp->room = (t_room *)ft_memalloc(sizeof(t_room));
}

int		room_name(t_output *otp, char *line1)
{
	int		i;
	t_room	*ptr;

	i = -1;
	create_name_room(otp);
	ptr = otp->room;
	while (line1[++i])
	{
		if (line1[i] == ' ')
		{
			while (ptr->next)
				ptr = ptr->next;
			ptr->name = ft_strsub(line1, 0, i);
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
	t_room	*ptr;

	i = -1;
	create_name_room(otp);
	ptr = otp->room;
	if (otp->number_room_start > -1)
		ft_error("start two times\n");
	while (line1[++i])
	{
		if (line1[i] == ' ')
		{
			while (ptr->next)
				ptr = ptr->next;
			ptr->name = ft_strsub(line1, 0, i);
			otp->number_room_start = ptr->numb;
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
	t_room	*ptr;

	i = -1;
	create_name_room(otp);
	ptr = otp->room;
	if (otp->number_room_end > -1)
		ft_error("end two times\n");
	while (line1[++i])
	{
		if (line1[i] == ' ')
		{
			while (ptr->next)
				ptr = ptr->next;
			ptr->name = ft_strsub(line1, 0, i);
			otp->number_room_end = ptr->numb;
			break ;
		}
		if (line1[i] == '-')
			ft_error("3bad room name, no '-' at the name3\n");
	}
	return (i);
}

int		valid_numb(char *line, int i)
{
	i++;
	while (line[i] && (line[i] != ' '))
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
	if (check_not_links(line1) && line1[0] != ' ' && line1[0] != 'L')
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
	if (check_not_links(line) && line[0] != ' ' && line[0] != 'L')
		j = room_name(otp, line);
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
	ft_strdel(&line);
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
			if (numb > 2147483647 || numb < -2147483648)
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

int		main(void)
{
	t_read		*read;
	t_output	out;
	t_room		*tmp;
	// int			i;

	read = NULL;
	// if (!(out = (t_output *)malloc(sizeof(t_output))))
	// 	return (-1);
	out.room = NULL;
	out.link = NULL;
	out.ants = 0;
	out.num_rooms = 0;
	find_numb_ants(&read, &out);

	find_rooms(&read, &out);
	write_input_on_console(read);
	tmp = out.room;
	while (tmp->next)
		tmp = tmp->next;
	out.num_rooms = tmp->numb + 1;
	// out->tmp = ft_strnew(out->num_rooms);
	if (!(out.tmp = (int *)ft_memalloc(sizeof(int))))
		ft_error("malloc5");
	// if (out->arr[out->number_room_start][out->number_room_end] == 1)
	// 	print_ants_way(out);
	// else
	// {
		func_set(&out, out.number_room_start, 5);// not good coord j! not i
		algo_lemin(&out, out.number_room_start, 0);
	// }
	//delete
	int a = -1;
	t_link *ptr;
	ptr = out.link;
	while (ptr)
	{
		a = -1;
		ft_printf("links\n");
		while (++a < ptr->len)
		{
			ft_printf("%1d", ptr->arlink[a]);
		}
		ft_printf("\n");
		ptr = ptr->next;
	}
	// delete_struct(&read, &out);
	// while (1);
	return (1);
}
