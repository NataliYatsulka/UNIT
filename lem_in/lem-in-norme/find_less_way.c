/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_less_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:29:18 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/06/27 18:29:18 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_ants_way(t_output *otp)
{
	int		i;
	t_room	*ptr;

	ptr = otp->room;
	while (ptr)
	{
		if (ptr->numb == otp->number_room_end)
			break ;
		ptr = ptr->next;
	}
	i = 1;
	while (i <= otp->ants)
	{
		ft_printf("\033[0;36mL%d\033[;0m-\033[0;36m%s\033[;0m", i, ptr->name);
		(i == otp->ants) ? (ft_printf("\n")) : (ft_printf(" "));
		i++;
	}
}

void	convert_num_to_rooms_name(t_output *otp, t_link *path)
{
	int		i;
	char	**s;
	t_room	*ptr;

	i = 0;
	s = (char **)ft_memalloc(sizeof(char *) * (path->len));
	while (++i < path->len)
	{
		ptr = otp->room;
		while (ptr && ptr->numb != path->arlink[i])
			ptr = ptr->next;
		s[i] = ptr->name;
	}
	otp->mas = s;
}

void	print_one_way(t_output *otp, int nbr, int i, int j)
{
	t_link	*tmp;

	tmp = otp->link;
	while (tmp)
	{
		if (tmp->numblink == nbr)
			break ;
		tmp = tmp->next;
	}
	convert_num_to_rooms_name(otp, tmp);
	while (++i <= (otp->ants + tmp->len - 1))
	{
		j = i - tmp->len + 1;
		while (++j <= i)
		{
			if (j <= otp->ants && j > 0)
				ft_printf("\033[0;32mL%d\033[;0m-\033[0;33m%s\033[;0m ",
					j, otp->mas[i - j + 1]);
		}
		ft_printf("\n");
	}
}

int		find_less_way(t_output *otp)
{
	int		nr;
	int		i;
	t_link	*ptr;

	ptr = NULL;
	if (otp->link != NULL)
		ptr = otp->link;
	else
		ft_error("no way from start to end\n");
	i = ptr->len;
	nr = 0;
	while (ptr)
	{
		if (i > ptr->len)
		{
			i = ptr->len;
			nr = ptr->numblink;
		}
		ptr = ptr->next;
	}
	return (nr);
}
