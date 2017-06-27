/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 19:19:47 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/05/17 19:19:47 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"

typedef struct		s_read
{
	char			*line;
	struct s_read	*nxt;
}					t_read;

typedef struct		s_room
{
	char			*name;
	int				numb;
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	int				*arlink;
	int				numblink;
	int				len;
	struct s_link	*next;
}					t_link;

typedef struct		s_output
{
	int				ants;
	int				num_rooms;
	int				*tmp;
	int				number_room_start;
	int				number_room_end;
	struct s_room	*room;
	struct s_link	*link;
	int				**arr;
	char			**mas;
}					t_output;

int					main(void);
void				init_struct(t_output *otp);
void				find_numb_ants(t_read **read, t_output *otp);
void				read_nub_ant(t_output *otp, char *line);

void				find_rooms(t_read **read, t_output *otp);
void				put_good_room(t_output *otp, char *line);
void				check_s_e_command(t_read **read, t_output *otp, char *line);
void				check_s_e_command_2(t_read **read, t_output *otp,
										char *line1);
void				put_coord_end(t_output *otp, char *line1);

void				put_coord_start(t_output *otp, char *line1);
int					valid_numb(char *line, int i);
int					room_name_end(t_output *otp, char *line1);
int					room_name_start(t_output *otp, char *line1);
int					room_name(t_output *otp, char *line1);

void				create_name_room(t_output *otp);
int					check_not_links(char *line);

void				find_links(t_read **read, t_output *otp, char *line);
void				read_name_links(t_read *read, t_output *otp);
void				write_in_struct_links(t_output *otp, char *line);
int					get_numb_room_for_link(t_output *otp, char *s);
void				matrix_for_links(t_output *otp, int k);

int					check_links(char *line);
void				find_same_name_room(t_output *otp);

void				algo_lemin(t_output *otp, int i, int count);
void				copy_link(t_output *otp, int count);
void				func_set(t_output *otp, int j, int k);
void				find_best_way(t_output *otp);
int					max_numb_way(t_output *otp);

int					find_less_way(t_output *otp);
void				print_one_way(t_output *otp, int nbr, int i, int j);
void				convert_num_to_rooms_name(t_output *otp, t_link *path);
void				print_ants_way(t_output *otp);

void				write_read(t_read **read, char *line);
void				write_input_on_console(t_read *read);
void				ft_error(char *s);

#endif
