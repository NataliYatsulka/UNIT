/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:28:29 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/06/27 18:28:35 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		max_numb_way(t_output *otp)
{
	int		i;
	int		count1;
	int		count2;

	count1 = 0;
	count2 = 0;
	i = -1;
	while (otp->arr[otp->number_room_start][++i] && i < otp->num_rooms)
	{
		if (otp->arr[otp->number_room_start][i] == 1)
			count1++;
	}
	i = -1;
	while (otp->arr[otp->number_room_end][++i] && i < otp->num_rooms)
	{
		if (otp->arr[otp->number_room_end][i] == 1)
			count2++;
	}
	return ((count1 >= count2) ? count2 : count1);
}

void	find_best_way(t_output *otp)
{
	int		k;

	k = max_numb_way(otp);
	if (k == 0)
		ft_error("no way\n");
	else if (k > 0)
		print_one_way(otp, find_less_way(otp), 0, 0);
}

void	func_set(t_output *otp, int j, int k)
{
	int		l;

	l = -1;
	while (++l < otp->num_rooms)
	{
		if (k == 5 && otp->arr[l][j] == 1)
			otp->arr[l][j] = k;
		else if (k == 1 && otp->arr[l][j] == 5)
			otp->arr[l][j] = k;
	}
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
		if (!(ptr->next = (t_link *)ft_memalloc(sizeof(t_link))))
			ft_error("malloc link2\n");
		ptr->next->numblink = ptr->numblink + 1;
		ptr = ptr->next;
	}
	if (!(ptr->arlink = (int *)ft_memalloc(count * sizeof(int))))
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
