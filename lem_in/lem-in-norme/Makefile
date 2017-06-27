#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/18 17:18:04 by nyatsulk          #+#    #+#              #
#    Updated: 2017/05/18 17:18:05 by nyatsulk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

CC = gcc
FL = -Wall -Wextra -Werror

FIL_I = ./includes/lemin.h
INCLUDES = -I $(FIL_I)

SOURCE = lem_in.c \
			algo_lemin.c \
			check_links.c \
			create_name_room.c \
			find_less_way.c \
			find_links.c \
			find_rooms.c \
			put_coord_start.c \
			write_read.c

OBJECTS = $(SOURCE:.c=.o)

LIBFT_DIR = ./libft/

MAKELIB = make -C libft/

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_DIR)libft.a
		$(CC) $(FL) $(OBJECTS) -o $(NAME) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(FL) -c $< -o $@

$(LIBFT_DIR)libft.a:
		make -C $(LIBFT_DIR)

.PHONY: clean fclean re

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
