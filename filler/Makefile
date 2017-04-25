#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/25 15:59:15 by nyatsulk          #+#    #+#              #
#    Updated: 2017/04/25 15:59:22 by nyatsulk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = filler

CC = gcc
FL = -Wall -Wextra -Werror

FIL_I = ./includes/ft_filler.h
INCLUDES = -I $(FIL_I)

SOURCE = main.c

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
