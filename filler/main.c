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

#define WHERE_READ 0 //0=з консолі, 3=зфайлу

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

int		ok_put(t_filler *f, int i, int j)
{
	int		k;
	int		l;

	k = -1;
	f->x_return = i;
	f->y_return = j;
	while (++k < f->t_x)
	{
		l = 0;
		while (l < f->t_y)
		{
			if (f->tkn[k][l] == '.')
				l++;
			else
			{
				f->map[i + k][j + l] = f->tkn[k][l];
				l++;
			}
		}
	}
	return (1);
}

int		check_map_and_tkn(t_filler *f, int i, int j)
{
	int		k;
	int		l;
	int		count;

	k = -1;
	count = 0;
	while (++k < f->t_x)
	{
		l = 0;
		while (l < f->t_y)
		{
			if ((f->map[i + k][j + l] == '.' || f->map[i + k][j + l] == f->sgn)
				&& (f->tkn[k][l] == '.' || f->tkn[k][l] == f->sgn))
			{
				if (f->map[i + k][j + l] == f->sgn && f->tkn[k][l] == f->sgn)
					count++;
				l++;
			}
			else
				return (0);
		}
	}
	return (count == 1 ? 1 : 0);
}

void	put_tkn_on_map(t_filler *f)
{
	int		i;
	int		j;

	i = -1;
	while (++i < f->len_map_x - f->t_x +1)
	{
		j = 0;
		while (j < f->len_map_y - f->t_y +1)
		{
			if (check_map_and_tkn(f, i, j) == 1)
			{
				f->x_return = i;
				f->y_return = j;
				return ;
			}
			j++;
		}
	}
}

// void	mas_malloc(t_filler *f, int x)
// {
// 	if (!(f->tkn = (char **)malloc((x + 1) * sizeof(char *))))
// 		return ;
// 	f->tkn[x] = NULL;
// }

// void	mas_malloc_map(t_filler *f, int x)
// {
// 	if (!(f->map = (char **)malloc((x + 1) * sizeof(char *))))
// 		return ;
// 	f->map[x] = NULL;
// }

void	place_token(t_filler *f)
{
	int		i;
	int		j;
	char		*line_n;


	i = 0;
	line_n = NULL;
	while (i < f->t_x)
	{
		get_next_line(WHERE_READ, &line_n);
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

int		module(int i, int j, int x, int y)
{
	int		res;

	res = 0;
	if ((i - j) <= 0)
		res = j - i;
	else
		res = i - j;
	if ((x - y) >= 0)
		res = res + x - y;
	else
		res = res + y - x;
	return (res);
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
			if (f->map[i][j] == f->sgn)//delete coment for me (-2) && for enemy (-1)
				f->distmap[i][j] = -2;
			else if (f->map[i][j] != '.' && f->map[i][j] != f->sgn)
				f->distmap[i][j] = -1;
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
		{
			if (f->map[i][j] == f->sgn)//delete coment for me (-2) && for enemy (-1)
				f->distmap[i][j] = -2;
			else if (f->map[i][j] != '.' && f->map[i][j] != f->sgn)
				f->distmap[i][j] = -1;
		}
	}
	put_d_map_2(f);
	// i = 0;			//test delete
	// j = 0;
	// while (j < f->len_map_x)
	// {
	// 	i = 0;
	// 	while (i < f->len_map_y)
	// 	{
	// 		ft_printf("distmap[%d][%d] = %d\n", j, i, f->distmap[j][i]);
	// 		i++;
	// 	}
	// 	j++;
	// }
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
	// mas_malloc(f, f->t_x);
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
	get_next_line(WHERE_READ, line);
	ft_strdel(line);
	if (!(f->map = (char **)malloc((f->len_map_x + 1) * sizeof(char *))))
		return ;
	f->map[f->len_map_x] = NULL;
	// mas_malloc_map(f, f->len_map_x);
	while (++i < f->len_map_x)
	{
		get_next_line(WHERE_READ, line);
		f->map[i] = ft_strsub(*line, 4, f->len_map_y);
		ft_strdel(line);
	}
	put_distance_map(f);
	get_next_line(WHERE_READ, line);
	read_token_num(f, line);
	return ;
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
	// int	fd;
	// int i = -1;


// #if WHERE_READ == 3
// 	open("/nfs/2016/n/nyatsulk/filler/22_04_17/n_yatsulk/test.c", O_RDONLY);
// #endif
// 	fd = open("/nfs/2016/n/nyatsulk/filler/22_04_17/n_yatsulk/test2.c", O_WRONLY);

	line = NULL;
	if (!(f = (t_filler *)ft_memalloc(sizeof(t_filler))))
		return (1);
	f->sgn = 'X';
	f->x_return = 0;
	f->y_return = 0;
	get_next_line(WHERE_READ, &line);
	if (ft_strnequ(line, "$$$ exec p1", 11))
		f->sgn = 'O';
	ft_strdel(&line);
	while (get_next_line(WHERE_READ, &line))
	{
		read_plato(f, &line);
		ft_strdel(&line);
		put_tkn_on_map(f);
		ft_printf("%d %d\n", f->x_return, f->y_return);
		delete_strct(f);
	}
	// #if WHERE_READ == 3
	// while (++i < f->len_map_x)
	// 	dprintf(fd, "%s \n", f->map[i]);
	// i = -1;
	// while (++i < f->t_x)
	// 	dprintf(fd, "%s %d %d/// %d %d\n", f->tkn[i], f->t_x, f->t_y, f->x_return, f->y_return);
	// dprintf(fd, "x_y_return %d %d\n", f->x_return, f->y_return);
	// close(3);
	// #endif

	return (1);
}
