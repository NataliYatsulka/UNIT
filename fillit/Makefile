#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/03 17:18:22 by nyatsulk          #+#    #+#              #
#    Updated: 2017/02/03 17:18:22 by nyatsulk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = fillit
CC = gcc
FL = -Wall -Wextra -Werror
OBJ = ./main.o \
	./ft_backtr.o \
	./ft_create_map.o \
	./ft_move.o \
	./ft_strlen.o \
	./ft_check_3.o \
	./ft_del_map.o \
	./ft_nb_split_word.o \
	./ft_strndup.o \
	./ft_check_d.o \
	./ft_error.o \
	./ft_print_map.o \
	./ft_strnew.o \
	./usage.o \
	./ft_check_h.o \
	./ft_fill_d.o \
	./ft_putchar.o \
	./ft_strsplit.o \
	./ft_check_n.o \
	./ft_fill_del_f.o \
	./ft_putstr.o \
	./ft_strsub.o \
	./ft_check_tetriminos_1.o \
	./ft_fill_f.o \
	./ft_read_file.o \
	./ft_valid.o \
	./ft_check_tetriminos_2.o \
	./ft_letter.o \
	./ft_srch_coor.o \
	./ft_x.o \
	./ft_coord.o \
	./ft_map_size.o \
	./ft_store.o \
	./ft_y.o \
	./ft_rec.o \
	./ft_print_map_exit.o
.PHONY: all clean fclean re
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(FL) -o $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
main.o: main.c
	$(CC) $(FL) -c main.c
ft_backtr.o: ft_backtr.c
	$(CC) $(FL) -c ft_backtr.c
ft_create_map.o: ft_create_map.c
	$(CC) $(FL) -c ft_create_map.c
ft_move.o: ft_move.c
	$(CC) $(FL) -c ft_move.c
ft_strlen.o: ft_strlen.c
	$(CC) $(FL) -c ft_strlen.c
ft_check_3.o: ft_check_3.c
	$(CC) $(FL) -c ft_check_3.c
ft_del_map.o: ft_del_map.c
	$(CC) $(FL) -c ft_del_map.c
ft_nb_split_word.o: ft_nb_split_word.c
	$(CC) $(FL) -c ft_nb_split_word.c
ft_strndup.o: ft_strndup.c
	$(CC) $(FL) -c ft_strndup.c
ft_check_d.o: ft_check_d.c
	$(CC) $(FL) -c ft_check_d.c
ft_error.o: ft_error.c
	$(CC) $(FL) -c ft_error.c
ft_print_map.o: ft_print_map.c
	$(CC) $(FL) -c ft_print_map.c
ft_strnew.o: ft_strnew.c
	$(CC) $(FL) -c ft_strnew.c
usage.o: usage.c
	$(CC) $(FL) -c usage.c
ft_check_h.o: ft_check_h.c
	$(CC) $(FL) -c ft_check_h.c
ft_fill_d.o: ft_fill_d.c
	$(CC) $(FL) -c ft_fill_d.c
ft_putchar.o: ft_putchar.c
	$(CC) $(FL) -c ft_putchar.c
ft_strsplit.o: ft_strsplit.c
	$(CC) $(FL) -c ft_strsplit.c
ft_check_n.o: ft_check_n.c
	$(CC) $(FL) -c ft_check_n.c
ft_fill_del_f.o: ft_fill_del_f.c
	$(CC) $(FL) -c ft_fill_del_f.c
ft_putstr.o: ft_putstr.c
	$(CC) $(FL) -c ft_putstr.c
ft_strsub.o: ft_strsub.c
	$(CC) $(FL) -c ft_strsub.c
ft_check_tetriminos_1.o: ft_check_tetriminos_1.c
	$(CC) $(FL) -c ft_check_tetriminos_1.c
ft_fill_f.o: ft_fill_f.c
	$(CC) $(FL) -c ft_fill_f.c
ft_read_file.o: ft_read_file.c
	$(CC) $(FL) -c ft_read_file.c
ft_valid.o: ft_valid.c
	$(CC) $(FL) -c ft_valid.c
ft_check_tetriminos_2.o: ft_check_tetriminos_2.c
	$(CC) $(FL) -c ft_check_tetriminos_2.c
ft_letter.o: ft_letter.c
	$(CC) $(FL) -c ft_letter.c
ft_srch_coor.o: ft_srch_coor.c
	$(CC) $(FL) -c ft_srch_coor.c
ft_x.o: ft_x.c
	$(CC) $(FL) -c ft_x.c
ft_coord.o: ft_coord.c
	$(CC) $(FL) -c ft_coord.c
ft_map_size.o: ft_map_size.c
	$(CC) $(FL) -c ft_map_size.c
ft_store.o: ft_store.c
	$(CC) $(FL) -c ft_store.c
ft_y.o: ft_y.c
	$(CC) $(FL) -c ft_y.c
ft_rec.o: ft_rec.c
	$(CC) $(FL) -c ft_rec.c
ft_print_map_exit.o: ft_print_map_exit.c
	$(CC) $(FL) -c ft_print_map_exit.c
	