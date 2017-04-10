#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/06 16:25:03 by nyatsulk          #+#    #+#              #
#    Updated: 2017/02/06 16:25:03 by nyatsulk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SOURCE = ft_printf.c		

OBJECTS = $(SOURCE:.c=.o)

LIB_DIR = ./libft/

LIB_INC = ./libft/libft.h

HEAD = libftprintf.h

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB_DIR)libft.a
	ar rc $(NAME) $(OBJECTS) $(LIB_DIR)*.o
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ -I $(LIB_DIR) -I $(LIB_INC) -I $(HEAD)

$(LIB_DIR)libft.a:
	make -C $(LIB_DIR)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all
