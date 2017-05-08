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
	while (++i < f->len_map_x - f->t_x)
	{
		j = 0;
		while (j < f->len_map_y - f->t_y)
		{//printf("i=%d j=%d,, len_x=%d len_y=%d,, t_x=%d t_y=%d yysy=%d xxx=%d\n", i, j, f->len_map_x,
			//f->len_map_y, f->t_x, f->t_y, f->len_map_y - f->t_y, f->len_map_x - f->t_x);
			if (check_map_and_tkn(f, i, j) == 1)
			{
				f->x_return = i;
				f->y_return = j;
				printf("%d %d\n", f->x_return, f->y_return);
				return ;

				// if (ok_put(f, i, j) == 1)
				// {
				// 	printf("%d %d\n", f->x_return, f->y_return);
				// 	return ;
				// }
			}
			j++;
		}
	}
}

void	mas_malloc(t_filler *f, int x)
{
	int		i;

	i = -1;
	if (!(f->tkn = (char **)malloc((x + 1) * sizeof(char *))))
		return ;
	f->tkn[x] = NULL;
}

void	mas_malloc_map(t_filler *f, int x)
{
	int		i;

	i = -1;
	if (!(f->map = (char **)malloc((x + 1) * sizeof(char *))))
		return ;
	f->map[x] = NULL;
	// while (++i < x)
	// {
	// 	f->map[i] = ft_strnew(y);
	// 	if (!f->map[i])
	// 		return ;
	// }
}

void	place_token(t_filler *f, char **line)
{
	int		i;
	int		j;

	i = -1;
	ft_strdel(line);
	while (++i < f->t_x)
	{
		get_next_line(WHERE_READ, line);
		f->tkn[i] = ft_strdup(*line);
		ft_strdel(line);
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
	// i = -1;											//test
	// while (++i < f->t_x)
	// 	dprintf(0, "%s %d %d///\n", f->tkn[i], f->t_x, f->t_y);
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
	//ft_strdel(&line);
	mas_malloc(f, f->t_x);
	place_token(f, line);
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

	i = 0;
	if (!f->len_map_x || !f->len_map_y)
		read_numb_max_xy(f, line);
	ft_strdel(line);
	get_next_line(WHERE_READ, line);
	ft_strdel(line);
	mas_malloc_map(f, f->len_map_x);
	while (!f->tkn && get_next_line(WHERE_READ, line))
	{
		if (i < f->len_map_x)
			f->map[i] = ft_strsub(*line, 4, f->len_map_y);
		i++;
		if ((*line)[0] != 'P')
			ft_strdel(line);
		else
		{
			// i = -1;									//test
			// while (++i < f->len_map_x)
			// 	dprintf(0, "%s \n", f->map[i]);	//test
			read_token_num(f, line);
		}
	}
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
	int	fd;
	// int i = -1;


#if WHERE_READ == 3
	open("/nfs/2016/n/nyatsulk/filler/22_04_17/n_yatsulk/test.c", O_RDONLY);
#endif
	fd = open("/nfs/2016/n/nyatsulk/filler/22_04_17/n_yatsulk/test2.c", O_WRONLY);

	line = NULL;
	if (!(f = (t_filler *)ft_memalloc(sizeof(t_filler))))
		return (1);
	f->sgn = 'X';
	get_next_line(WHERE_READ, &line);
	if (ft_strnequ(line, "$$$ exec p1", 11))
		f->sgn = 'O';
	ft_strdel(&line);

	// get_next_line(WHERE_READ, &line);
	// read_plato(f, &line);
	// put_tkn_on_map(f);
	while (get_next_line(WHERE_READ, &line))
	{
		read_plato(f, &line);
		// printf("%s\n", "put on map");
		put_tkn_on_map(f);
		f->t_x = 0;
	}
	

	// get_next_line(WHERE_READ, &line);
	// read_plato(f, &line);
	// put_tkn_on_map(f);
	// #if WHERE_READ == 3
	// while (++i < f->len_map_x)
	// 	dprintf(fd, "%s \n", f->map[i]);
	// i = -1;
	// while (++i < f->t_x)
	// 	dprintf(fd, "%s %d %d/// %d %d\n", f->tkn[i], f->t_x, f->t_y, f->x_return, f->y_return);
	// dprintf(fd, "x_y_return %d %d\n", f->x_return, f->y_return);
	// close(3);
	// #endif

	return (0);
}
