/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:54:01 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/01/17 16:54:02 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list_1	*ft_fd(const int fd, t_list_1 *list)
{
	if (list == NULL)
	{
		list = malloc(sizeof(t_list_1));
		list->str = NULL;
		list->f_d = fd;
		list->nex = NULL;
	}
	else
	{
		while (list && fd != list->f_d)
		{
			if (list->nex == NULL)
			{
				if ((list->nex = malloc(sizeof(t_list_1))) == NULL)
					return (NULL);
				list = list->nex;
				list->str = NULL;
				list->nex = NULL;
				list->f_d = fd;
				break ;
			}
			list = list->nex;
		}
	}
	return (list);
}

static void		check_2(char *cut, t_list_1 *list)
{
	char			*t;

	if (cut && list->str)
	{
		t = list->str;
		list->str = ft_strjoin(cut, list->str);
		ft_strdel(&(cut));
	}
}

static t_list_1	*check(const int fd, t_list_1 **head)
{
	t_list_1		*list;

	list = ft_fd(fd, *head);
	if (*head == NULL)
		*head = list;
	return (list);
}

static int		ft_int(t_list_1 *list, char **line)
{
	if ((list->str)[0] == '\0')
		return (0);
	*line = list->str;
	list->str = (list->t ? ++(list->t) : NULL);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	t_list_1		*list;
	static t_list_1	*head;
    int j = 0;

	list = check(fd, &head);
	list->cut = NULL;
	list && list->str ? list->cut = ft_strdup(list->str) : 0;
	list->str = ft_strnew(BUFF_SIZE);
	list->p = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !list || !list->str || !(line) ||
		!(list->p) || read(fd, list->p, 0) == -1)
		return (-1);
	check_2(list->cut, list);
	while ((list->t = ft_strchr(list->str, '\n')) == NULL)
	{
		ft_bzero(list->p, BUFF_SIZE);
        j = read(fd, list->p, BUFF_SIZE);
        if (j == 0)
            
//		if (read(fd, list->p, BUFF_SIZE) == 0)
			return (ft_int(list, line));
		list->t = list->str;
		list->str = ft_strjoin(list->str, list->p);
		free((list->t));
	}
	*line = ft_strsub(list->str, 0, list->t - list->str);
	list->str = ++(list->t);
	return (1);
}
