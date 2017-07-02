/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:56:52 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:56:52 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_letter(t_list *list)
{
	char	letter;

	letter = 'A';
	while (list)
	{
		list->letter = letter;
		list = list->next;
		letter++;
	}
}
