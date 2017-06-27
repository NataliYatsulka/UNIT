/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:30:20 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/06/27 18:30:20 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_error(char *s)
{
	write(1, "\033[0;31mERROR: ", ft_strlen("\033[0;31mERROR: "));
	write(1, s, ft_strlen(s));
	write(1, "\033[;0m", ft_strlen("\033[;0m"));
	exit(1);
}

void	write_input_on_console(t_read *read)
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
