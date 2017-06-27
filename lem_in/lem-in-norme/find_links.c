/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:29:34 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/06/27 18:29:38 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	matrix_for_links(t_output *otp, int k)
{
	int		m;
	int		j;
	t_room	*ptr;

	ptr = otp->room;
	while (ptr->next)
	{
		k++;
		ptr = ptr->next;
	}
	j = -1;
	if (!(otp->arr = (int **)malloc((k + 1) * sizeof(int *))))
		ft_error("malloc for arrs\n");
	otp->arr[k + 1] = NULL;
	while (++j < k + 1)
		if (!(otp->arr[j] = (int *)malloc((k + 1) * sizeof(int))))
			ft_error("malloc for arrs11\n");
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

void	read_name_links(t_read *read, t_output *otp)
{
	char	*line1;

	while (get_next_line(0, &line1))
	{
		if (line1[0] == '#' && line1[1] == '#')
		{
			if (ft_strequ(line1, "##start") || ft_strequ(line1, "##end"))
				ft_error("##start or ##end in block links\n");
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
}

void	find_links(t_read **read, t_output *otp, char *line)
{
	find_same_name_room(otp);
	if (line == NULL)
		ft_error("empty line\n");
	if (otp->number_room_start < 0 || otp->number_room_end < 0)
		ft_error("no end or start in block room\n");
	if (line != NULL)
	{
		if (check_links(line))
		{
			matrix_for_links(otp, 0);
			write_in_struct_links(otp, line);
			write_read(read, line);
			read_name_links(*read, otp);
		}
		else
			ft_error("smth went wrong with read links, no valid links\n");
	}
}
