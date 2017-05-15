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

void	delete_strct(t_filler *f)
{
	int		i;

	i = -1;
	f->t_x = 0;
	f->t_y = 0;
	while (f->tkn[++i])
		ft_strdel(&f->tkn[i]);
	f->tkn = NULL;
	i = -1;
	while (f->map[++i])
		ft_strdel(&f->map[i]);
	f->x_return = 0;
	f->y_return = 0;
}

int		check_map_and_tkn(t_filler *f, int i, int j)
{
	int		k;
	int		l;
	int		s;
	int		count;

	count = 0;
	s = 0;
	k = -1;
	while (f->tkn[++k])
	{
		if (k && !f->map[++i])
			return (0);
		l = -1;
		while (f->tkn[k][++l])
		{
			if (!f->map[i][j + l] || (f->tkn[k][l] == f->sgn
				&& (f->map[i][j + l] != f->sgn && f->map[i][j + l] != '.')))
				return (0);
			else if (f->tkn[k][l] == f->sgn && f->map[i][j + l] == f->sgn)
				count++;
			else if (f->map[i][j + l] == '.')
				s = s + f->distmap[i][j + l];
		}
	}
	return ((count != 1) ? 0 : s);
}

int		put_tkn_on_map(t_filler *f)
{
	int		i;
	int		j;
	int		d;

	i = 0;
	while (f->map[i])
	{
		j = 0;
		while (f->map[i][j])
		{
			d = check_map_and_tkn(f, i, j);
			if (d && d < f->sum)
			{
				f->x_return = i;
				f->y_return = j;
				f->sum = d;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	place_token(t_filler *f)
{
	int		i;
	int		j;
	char	*line_n;

	i = 0;
	line_n = NULL;
	while (i < f->t_x)
	{
		get_next_line(0, &line_n);
		f->tkn[i] = ft_strdup(line_n);
		i++;
		ft_strdel(&line_n);
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

int		module(int x1, int y1, int x2, int y2)
{
	int		res;

	res = 0;
	if ((x1 - x2) <= 0)
		res = x2 - x1;
	else
		res = x1 - x2;
	if ((y1 - y2) >= 0)
		res = res + y1 - y2;
	else
		res = res + y2 - y1;
	return (res);
}

void	write_numb_map(t_filler *f)
{
	int		i;
	int		j;
	int		dist;

	i = -1;
	dist = 0;
	while (++i < f->len_map_x)
	{
		j = -1;
		while (++j < f->len_map_y)
		{
			if (f->map[i][j] == '.' || f->map[i][j] != f->sgn)
			{
				dist = module(i, j, f->enem_x, f->enem_y);
				if (dist <= f->distmap[i][j])
					f->distmap[i][j] = dist;
			}
		}
	}
}

void	put_d_map_2(t_filler *f)
{
	int		i;
	int		j;

	i = -1;
	while (++i < f->len_map_x)
	{
		j = -1;
		while (++j < f->len_map_y)
		{
			if (f->map[i][j] == f->sgn)
				f->distmap[i][j] = -2;
			else if (f->map[i][j] != '.' && f->map[i][j] != f->sgn)
			{
				f->distmap[i][j] = -1;
				f->enem_x = i;
				f->enem_y = j;
				write_numb_map(f);
			}
		}
	}
}

void	put_distance_map(t_filler *f)
{
	int		i;
	int		j;

	i = -1;
	if (!(f->distmap = (int **)ft_memalloc((f->len_map_x + 1) * sizeof(int *))))
		return ;
	while (i < f->len_map_x)
	{
		if (!(f->distmap[++i] = (int *)ft_memalloc((f->len_map_y + 1)
			* sizeof(int))))
			return ;
	}
	i = -1;
	while (++i < f->len_map_x)
	{
		j = -1;
		while (++j < f->len_map_y)
			f->distmap[i][j] = 500;
	}
	f->sum = 500;
	put_d_map_2(f);
}

void	read_token_num(t_filler *f, char **line)
{
	int		j;

	j = 0;
	while ((*line)[j] && ((*line)[j] < 48 || (*line)[j] > 57))
		j++;
	f->t_x = ft_atoi(&(*line)[j]);
	while ((*line)[j] && ((*line)[j] >= 48 && (*line)[j] <= 57))
		j++;
	f->t_y = ft_atoi(&(*line)[j]);
	if (!(f->tkn = (char **)malloc((f->t_x + 1) * sizeof(char *))))
		return ;
	f->tkn[f->t_x] = NULL;
	place_token(f);
}

void	read_numb_max_xy(t_filler *f, char **line)
{
	int		j;

	j = 0;
	while ((*line)[j] && ((*line)[j] < 48 || (*line)[j] > 57))
		j++;
	f->len_map_x = ft_atoi(&(*line)[j]);
	while ((*line)[j] && ((*line)[j] >= 48 && (*line)[j] <= 57))
		j++;
	f->len_map_y = ft_atoi(&(*line)[j]);
}

void	read_plato(t_filler *f, char **line)
{
	int		i;

	i = -1;
	if (!f->len_map_x || !f->len_map_y)
		read_numb_max_xy(f, line);
	ft_strdel(line);
	get_next_line(0, line);
	ft_strdel(line);
	if (!(f->map = (char **)malloc((f->len_map_x + 1) * sizeof(char *))))
		return ;
	f->map[f->len_map_x] = NULL;
	while (++i < f->len_map_x)
	{
		get_next_line(0, line);
		f->map[i] = ft_strsub(*line, 4, f->len_map_y);
		ft_strdel(line);
	}
	put_distance_map(f);
	get_next_line(0, line);
	read_token_num(f, line);
	return ;
}

int		main(void)
{
	char		*line;
	t_filler	*f;

	line = NULL;
	if (!(f = (t_filler *)ft_memalloc(sizeof(t_filler))))
		return (1);
	f->sgn = 'X';
	get_next_line(0, &line);
	if (ft_strnequ(line, "$$$ exec p1", 11))
		f->sgn = 'O';
	ft_strdel(&line);
	while (get_next_line(0, &line))
	{
		read_plato(f, &line);
		ft_strdel(&line);
		put_tkn_on_map(f);
		ft_printf("%d %d\n", f->x_return, f->y_return);
		delete_strct(f);
	}
	return (1);
}
