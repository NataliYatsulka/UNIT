/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:45:06 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/04/25 16:45:06 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define WHERE_READ 3 //0=з консолі, 3=зфайлу

// void	malloc_for_two_mas(char **s, int x, int y)//libft plus
// {
// 	int		i;

// 	i = -1;
// 	if (!(s = (char **)ft_memalloc((y + 1) * sizeof(char *))))// y+1????
// 		return ;
// 	while (++i < x)
// 	{
// 		s[i] = ft_strnew(y);
// 		if (!s[i])
// 			return ;
// 	}
// }

void	mas_malloc(t_filler *f, int x, int y)
{
	int		i;

	i = -1;
	if (!(f->tkn = (char **)ft_memalloc((y + 1) * sizeof(char *))))
		return ;
	while (++i < x)
	{
		f->tkn[i] = ft_strnew(y);
		if (!f->tkn[i])
			return ;
	}
}

void	place_token(t_filler *f, char *line)
{
	int		i;
	int		j;

	i = -1;
	while (++i < f->t_x)
	{
		f->tkn[i] = line;
		get_next_line(WHERE_READ, &line);
	}
	i = -1;
	while (++i < f->t_x)
	{
		j = -1;
		while (++j < f->t_y)
		{
			if (f->tkn[i][j] == '*')
				f->tkn[i][j] = f->sgn;
		}
	}
}

void	read_token_num(t_filler *f, char *line)
{
	int		j;

	j = 0;
	while (line[j] && (line[j] < 48 || line[j] > 57))
		j++;
	f->t_x = ft_atoi(&line[j]);
	while (line[j] && (line[j] >= 48 && line[j] <= 57))
		j++;
	f->t_y = ft_atoi(&line[j]);
	ft_strdel(&line);
	mas_malloc(f, f->t_x, f->t_y);
	while (get_next_line(WHERE_READ, &line))
		place_token(f, line);
}

void	read_numb_max_xy(t_filler *f, char *line)
{
	int		j;

	j = 0;
	while (line[j] && (line[j] < 48 || line[j] > 57))
		j++;
	f->len_map_x = ft_atoi(&line[j]);
	while (line[j] && (line[j] >= 48 && line[j] <= 57))
		j++;
	f->len_map_y = ft_atoi(&line[j]);
}

void	put_coord_xo(t_filler *f, char *line, int i, int j)
{
	if (line[j] == 'X')
	{
		f->xx = i;
		f->xy = j - 3;
	}
	else if (line[j] == 'O')
	{
		f->ox = i;
		f->oy = j - 3;
	}
}

char	*read_plato(t_filler *f, char *line)
{
	int		i;
	int		j;

	i = 0;
	if (!f->len_map_x || !f->len_map_y)
		read_numb_max_xy(f, line);
	ft_strdel(&line);
	get_next_line(WHERE_READ, &line);
	ft_strdel(&line);
	while (get_next_line(WHERE_READ, &line))
	{
		j = 0;
		i++;
		while (line[j] && line[j] != 'P' && ((line[j] >= 48 && line[j] <= 57) ||
			line[j] == '.' || line[j] == ' '))
			j++;
		put_coord_xo(f, line, i, j);
		if (line[j] != 'P')
			ft_strdel(&line);
		else
			return (line);
	}
	return (NULL);
}

// все нулями робить ft_memaloc
// void	list_f_zero(void)
// {
// 	f->sgn = 'X';
// 	f->len_map_x = 0;
// 	f->len_map_y = 0;
// 	return (f);
// }

int		main(void)
{
	char		*line;
	t_filler	*f;

#if WHERE_READ == 3
	open("/nfs/2016/n/nyatsulk/filler/22_04_17/n_yatsulk/test.c", O_RDONLY);
#endif

	line = NULL;
	if (!(f = (t_filler *)ft_memalloc(sizeof(t_filler))))
		return (1);
	f->sgn = 'X';
	get_next_line(WHERE_READ, &line);
	if (ft_strnequ(line, "$$$ exec p1", 11))
		f->sgn = 'O';
	ft_strdel(&line);
	while (get_next_line(WHERE_READ, &line))
	{
		//leak line перепресвоюється????
		line = read_plato(f, line);
		read_token_num(f, line);
		// put_tkn_on_map_algo(f);
		write(1, "main\n", 5);
	}
	//ft_strdel(&line);
	printf("end of program\n");
	return (0);
	#if WHERE_READ == 3
		close(3);
	#endif
	return (0);
}
