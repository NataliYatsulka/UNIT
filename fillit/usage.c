/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:57:59 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:57:59 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	usage(char *s)
{
	write(1, "usage: ", 7);
	ft_putstr(s);
	write(1, " file\n", 6);
	exit(0);
}
