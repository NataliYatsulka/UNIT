/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 21:17:37 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/06/30 21:17:38 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>//delete

void	ft_error(char *s)
{
	write(1, "\033[0;31mERROR: ", ft_strlen("\033[0;31mERROR: "));
	write(1, s, ft_strlen(s));
	write(1, "\033[;0m", ft_strlen("\033[;0m"));
	exit(1);
}
void	**ft_malloc_mas(int i)
{
	void	**tmp;

	tmp = (void **)ft_memalloc((i + 1) * sizeof(void *));
	return (tmp);
}

int		len_of_mas(char **p)
{
	int		count;

	count = 0;
	while (*p && *p != NULL)
	{
		p++;
		count++;
	}
	return (count);
}

void	write_coord(t_fdf *f, char **s, int count, int i)
{
	int		j;

	j = -1;
	// printf("###################count=%d\n", count);
	if (f->num_map_col && f->num_map_col <= count)// && f->num_map_col == count)
	{
		// ft_printf("col=%d, row=%d\n", f->num_map_col, f->num_map_row);//delete
		f->arr_coord[i] = (t_cfdf *)ft_memalloc(sizeof(t_cfdf) * f->num_map_col);
		while (++j < f->num_map_col)
		{
			(f->arr_coord[i][j]).x = (float)i;
			(f->arr_coord[i][j]).y = (float)j;
			(f->arr_coord[i][j]).z = (float)ft_atoi(s[j]);
		}
	}
	else
		ft_error("bad line\n");
}

void	read_num_of_col(t_fdf *f)
{
	int		count;
	int		i;

	i = -1;
	count = 0;
	count = len_of_mas(ft_strsplit(f->map[++i], ' '));
	if (count > 0)
		f->num_map_col = count;
	else
		ft_error("no column in map\n");
	f->arr_coord = (t_cfdf **)ft_malloc_mas(f->num_map_row);
	f->arr_for_degree = (t_cfdf **)ft_malloc_mas(f->num_map_row);
	i = -1;
	while (++i < f->num_map_row)
		write_coord(f, ft_strsplit(f->map[i], ' '),
			len_of_mas(ft_strsplit(f->map[i], ' ')), i);


	int k = -1;//delete
	while (++k < f->num_map_row)
	{
		int j = -1;
		while (++j < f->num_map_col)
		{
			// printf("f->x= %f, f->y= %f, f->z= %f\n", (f->arr_coord[k][j]).x , (f->arr_coord[k][j]).y ,(f->arr_coord[k][j]).z);
			printf("%3.0f ", (f->arr_coord[k][j]).z);

		}
		printf("\n");
	}
	ft_printf("okkk'\n");
}

void	read_map(t_fdf *f)
{
	int		i;

	i = -1;
	if ((f->fd = open(f->av, O_RDONLY)) < 0)
		ft_error("bad opening the file1\n");
	while (get_next_line(f->fd, &(f->line)))
	{
		f->num_map_row++;
		ft_strdel(&(f->line));
	}
	close(f->fd);
	if ((f->fd = open(f->av, O_RDONLY)) < 0)
		ft_error("bad opening the file2\n");
	if (f->num_map_row > 0)
	{
		f->map = (char **)ft_memalloc(sizeof(char *) * f->num_map_row);
		while (get_next_line(f->fd, &(f->line)) && ++i < f->num_map_row)
		{
			f->map[i] = ft_strdup((f->line));
			ft_strdel(&(f->line));
		}
		f->map[i + 1] = NULL;
	}
	close(f->fd);
}

int		main(int ac, char **av)
{
	t_fdf	*f;

	if (!(f = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		return (-1);
	if (ac != 2)
		usage(av[0]);
	f->av = av[1];
	// intit_struct_fdf(f);
	read_map(f);
	read_num_of_col(f);
	// put_coord_on_map(f);

	// int i = -1;//delete
	// while (++i < f->num_map_row+1)
	// {
	// 	ft_printf("%s\n", f->map[i]);
	// }
	// ft_printf("num_map_row = %d\n", f->num_map_row);
	// ft_printf("okkk'\n");
	// ft_printf("ok %d\n", 10);
	return (0);
}
