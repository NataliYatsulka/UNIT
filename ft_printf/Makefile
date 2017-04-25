#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/21 21:17:21 by nyatsulk          #+#    #+#              #
#    Updated: 2017/04/21 21:17:22 by nyatsulk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SOURCE = ft_printf.c\
		find_percent.c\
		ft_init_flags.c\
		ft_printf.c\
		ft_put_len_space.c\
		ft_put_nbr.c\
		ft_putnstr.c\
		ft_rest.c\
		ft_s_n.c\
		ft_spec_c_c.c\
		ft_spec_d_i.c\
		ft_spec_o_o_x_x.c\
		ft_spec_s_s.c\
		ft_spec_u_u.c\
		ft_spec_x_x.c

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
