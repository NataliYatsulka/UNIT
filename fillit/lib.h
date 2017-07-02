/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:18:32 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/02/03 17:18:32 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIB_H
# define _LIB_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	char			*str;
	int				x[4];
	int				y[4];
	char			letter;
	int				*map_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_backtr(t_list *list);
void				ft_del_map(char **map, int map_size);
int					ft_y(char **map, int map_size, int x, int y);
int					ft_x(char **map, int map_size, int x, int y);
char				**ft_fill_d(t_list *list, char **map);
int					ft_map_size(t_list *list);
void				ft_coord(t_list *list);
void				ft_move(t_list *list);
void				ft_letter(t_list *list);
char				**ft_strsplit(char const *s, char c);
int					ft_nb_split_word(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
t_list				*ft_store(char *s);
char				*ft_strndup(const char *s1, int n);
void				usage(char *s);
void				ft_error(void);
int					ft_check_3(char *s);
int					ft_check_n(char *s);
int					ft_check_h(char *s);
int					ft_check_d(char *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
int					ft_check_tetriminos_2(char *s);
int					ft_valid(char *s);
int					ft_check_tetriminos_1(char *s);
char				*ft_strnew(size_t size);
char				*ft_read_file(char *s);
void				ft_rec(t_list *list, char **map, int x, int y);
int					ft_fill_f(t_list *list, char **map, int x, int y);
void				ft_fill_del_f(t_list *l, char **map, int x, int y);
char				**ft_srch_coor(t_list *list, char **map, int x, int y);
void				ft_print_map(t_list *list, char **map);
char				**ft_create_map(t_list *list, int map_size);
void				ft_print_map_exit(t_list *list, char **map);
void				ft_print_map_exit(t_list *list, char **map);
void				ft_rec(t_list *l, char **m, int x, int y);

#endif
