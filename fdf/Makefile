#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/30 21:25:16 by nyatsulk          #+#    #+#              #
#    Updated: 2017/06/30 21:25:18 by nyatsulk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CC = gcc
FL = -Wall -Wextra -Werror

FIL_I = fdf.h
INCLUDES = -I $(FIL_I)

SOURCE = fdf.c

OBJECTS = $(SOURCE:.c=.o)

LIBFT_DIR = ./libft/

MAKELIB = make -C libft/

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_DIR)libft.a
		$(CC) $(FL) $(MLX_FLAGS) $(OBJECTS) -o $(NAME) -L$(LIBFT_DIR) -lft

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
