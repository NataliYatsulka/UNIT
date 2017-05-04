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

int		ok_put(t_filler *f, int i, int j)
{
	int		k;
	int		l;

	k = -1;
	f->x_return = i - 1;
	f->y_return = j - 1;
	while (++k < f->t_y)
	{
		l = 0;
		while (l < f->t_x)
		{
			f->map[i][j] = f->tkn[k][l];
			l++;
			j++;
		}
		i++;
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
	while (i < f->len_map_y - f->t_y && ++k < f->t_y)
	{
		l = 0;
		while (j < f->len_map_x - f->t_x && l < f->t_x)
		{
			// printf("%s\n",&(f->map)[i][j] );
			// printf("try: %d:%d; map = %c; tkn = %c \n", i+k, j+l, f->map[i + k][j + l], f->tkn[k][l]);
			if ((f->map[i + k][j + l] == '.' || f->map[i + k][j + l] == f->sgn) &&
				(f->tkn[k][l] == '.' || f->tkn[k][l] == f->sgn))
			{
				if (f->map[i + k][j + l] == f->sgn && f->tkn[k][l] == f->sgn)
					count++;
				l++;
			}
			else
				return (0);
		}
		// i = i + f->len_map_y + 1;
	}
	//printf("\n");
	// while (i < f->len_map_y - f->t_y && ++k < f->t_y)
	// {
	// 	l = 0;
	// 	while (j < f->len_map_x - f->t_x && l < f->t_x)
	// 	{
	// 		// printf("%s\n",&(f->map)[i][j] );
	// 		if ((f->map[i][j] == '.' || f->map[i][j] == f->sgn) &&
	// 			(f->tkn[k][l] == '.' || f->tkn[k][l] == f->sgn))
	// 		{
	// 			if (f->map[i][j] == f->sgn && f->tkn[k][l] == f->sgn)
	// 				count++;
	// 			l++;
	// 			j++;
	// 		}
	// 		else
	// 			return (0);
	// 	}
	// 	i = i + f->len_map_y + 1;
	// }
	if (count == 1)
		return (1);
	else
		return (0);		
}

void	put_tkn_on_map(t_filler *f)
{
	int		i;
	int		j;

	i = -1;
	while (++i < f->len_map_y - f->t_y)
	{
		j = 0;
		while (j < f->len_map_x - f->t_x)
		{
			
			// printf("%d:%d ", i, j);
			if (check_map_and_tkn(f, i, j) == 1)
			{
				if (ok_put(f, i, j) == 1)
				{
					ft_printf("%d %d", f->x_return, f->y_return);
					return ;
				}
			}
			j++;
			// else
			// 	;
		}
		// printf("\n");
	}
}

void	mas_malloc(t_filler *f, int y)
{
	int		i;

	i = -1;
	if (!(f->tkn = (char **)ft_memalloc((y + 1) * sizeof(char *))))
		return ;
	// while (++i < x)
	// {
	// 	f->tkn[i] = ft_strnew(y);
	// 	if (!f->tkn[i])
	// 		return ;
	// }
}

void	mas_malloc_map(t_filler *f, int x, int y)
{
	int		i;

	i = -1;
	if (!(f->map = (char **)ft_memalloc((y + 1) * sizeof(char *))))
		return ;
	while (++i < x)
	{
		f->map[i] = ft_strnew(y);
		if (!f->map[i])
			return ;
	}
}

// void	get_coord_tkn(t_filler *f)
// {

// }

void	place_token(t_filler *f, char *line)
{
	int		i;
	int		j;

	i = -1;
	while (++i < f->t_x)
	{
		f->tkn[i] = ft_strdup(line);
		ft_strdel(&line);
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
	mas_malloc(f, f->t_y);
	while (get_next_line(WHERE_READ, &line))
		place_token(f, line);
//	get_coord_tkn(f);
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

// void	put_coord_xo(t_filler *f, char *line, int i, int j)
// {
// 	if (line[j] == 'X')
// 	{
// 		f->xx = i;
// 		f->xy = j - 3;
// 	}
// 	else if (line[j] == 'O')
// 	{
// 		f->ox = i;
// 		f->oy = j - 3;
// 	}
// }

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
	mas_malloc_map(f, f->len_map_x, f->len_map_y);
	while (get_next_line(WHERE_READ, &line))
	{
		j = 0;
		if (i < f->len_map_y)
			f->map[i] = ft_strsub(line, 4, f->len_map_y);
		i++;
		// while (line[j] && line[j] != 'P' && ((line[j] >= 48 && line[j] <= 57) ||
		// 	line[j] == '.' || line[j] == ' '))
		// 	j++;
		// put_coord_xo(f, line, i, j);
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
		line = read_plato(f, line);
		read_token_num(f, line);
		put_tkn_on_map(f);
//		algo(f);
		//write(1, "main\n", 5);
	}
	//ft_strdel(&line);
	//printf("end of program\n");
	//printf("%d %d\n", f->x_return, f->y_return);
	return (0);
	#if WHERE_READ == 3
		close(3);
	#endif
	return (0);
}
