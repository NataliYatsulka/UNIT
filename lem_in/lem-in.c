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
	t_read	*ptr;

	ptr = *read;
	if (!(list = (t_read *)malloc(sizeof(t_read))))
		ft_error("1\n");
	while (ptr && ptr->nxt)
	{
		ptr = ptr->nxt;
	}
	ptr->nxt = list;
	list->nxt = NULL;
	list->line = ft_strdup(line);
}

////////////////////

void	check_start_end_command(t_read *read, t_output *otp, char *line)
{
	// int		i;
	char	*line1;

	// i = 0;
	line1 = NULL;
	// while (line[i])
	// {
		if (ft_strequ(line, "##start"))
		{
			if (otp->count_start > 0)
				ft_error("more than one start");
			write_read(&read, line);
			get_next_line(0, &line1);

		}

		if (ft_strequ(line, "##end"))
				ft_error("no numb ants before command\n");
	// }
}

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

int		ft_atoi_for_lemin(const char *str, int i)
{
	int		res;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

// void	put_end(t_output *otp)
// {
// 	char	*line1;
// 	int		i;

// 	i = 0;
// 	line1 = NULL;
// 	if (otp->end)
// 		ft_error("two times end");
// 	get_next_line(0, line1);
// 	check_not_links(line1);
// 	otp->end = ft_strchr(line1, ' ');
// 	while (line1[i])
// 	{
// 		if (!(ft_isdigit(line1[i])))
// 			i++;
// 		else
// 		{
// 			otp->x_end = ft_atoi_for_lemin(line1, i);
// 			otp->y_end = ft_atoi_for_lemin(line1, i + ft_strlen(otp->x_end) + 1);
// 		}
// 	}
// 	ft_strdel(&line1);
// }

// void	put_start(t_output *otp)
// {
// 	char	*line1;
// 	int		i;

// 	i = 0;
// 	line1 = NULL;
// 	if (otp->start)
// 		ft_error("two times start");
// 	get_next_line(0, line1);
// 	check_not_links(line1);
// 	otp->start = ft_strchr(line1, ' ');
// 	while (line1[i])
// 	{
// 		if (!(ft_isdigit(line1[i])))
// 			i++;
// 		else
// 		{
// 			otp->x_start = ft_atoi_for_lemin(line1, i);
// 			otp->y_start = ft_atoi_for_lemin(line1, i + ft_strlen(otp->x_start) + 1);
// 		}
// 	}
// 	ft_strdel(&line1);
// }

void	find_rooms(t_read **read, t_output *otp)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) && check_not_links(line))
	{
		// if ((line[0] == '#' && line[1] != '#') || ((line[0] == '#' &&line[1] != '#')
		// && (!ft_strequ(line, "##start") || !ft_strequ(line, "##end"))))
		// 	write_read(read, line);
		// else if (ft_strequ(line, "##start"))// || ft_strequ(line, "##end"))
		// 	put_start(otp);
		// else if (ft_strequ(line, "##end"))
		// 	put_end(otp);
		if (line[0] == '#' && line[1] == '#')
		{
			check_start_end_command(&read, otp, line);
			write_read(read, line);
		}
		else if (line[0] == '#')
			write_read(read, line);
		else
		{
			check_on_space(otp, line);
			// put_room_numb(otp);
			write_read(read, line);
		}
		ft_strdel(&line);
	}
	if (!*line)
		ft_error("no line");
}

/*
**		ants
*/

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
	if (!*line)
		ft_error("no line");
}

int		main(void)
{
	t_read		*read;
	t_output	*out;

	if (!(read = (t_read *)ft_memalloc(sizeof(t_read))))
		return (-1);
	if (!(out = (t_output *)ft_memalloc(sizeof(t_output))))
		return (-1);
	find_numb_ants(&read, out);
	find_rooms(&read, out);
	return (1);
}
