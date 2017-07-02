/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:58:10 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 16:58:10 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_read_file(char *s)
{
	int		fd;
	char	buf;
	char	*tmp;
	int		i;

	i = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
		ft_error();
	while (read(fd, &buf, 1))
		i++;
	if (i > 546)
		ft_error();
	if (close(fd) < 0)
		ft_error();
	tmp = ft_strnew(i);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		ft_error();
	else
		read(fd, tmp, i);
	if (close(fd) < 0)
		ft_error();
	tmp[i] = '\0';
	return (tmp);
}
