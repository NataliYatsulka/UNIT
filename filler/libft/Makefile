#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 14:34:10 by nyatsulk          #+#    #+#              #
#    Updated: 2016/12/06 13:12:59 by nyatsulk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = libft.a

SRC = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strcmp.c \
		ft_strlen.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_toupper.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_tolower.c \
		ft_strstr.c \
		ft_strdup.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_strlcat.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_nb_split_word.c \
		ft_itoa.c \
		ft_nb_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c \
		ft_printf.c\
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

OBJ = $(SRC:.c=.o)

FL = -Wall -Wextra -Werror

HEAD = ./libft.h

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc -Wall -Werror -Wextra -I ./includes/libft.h -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:     fclean all
