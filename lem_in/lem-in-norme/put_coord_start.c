/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_coord_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:30:11 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/06/27 18:30:12 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
