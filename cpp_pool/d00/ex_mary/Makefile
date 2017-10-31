
NAME = phone

SOURCE = Phone_book.class.cpp\
		main.cpp\

OBJECTS = $(SOURCE:%.cpp=%.o)

CC = clang++
FLAG = -Wall -Wextra -Werror

.PHONY: all fast clean fclean

all: main

%.o: %.cpp
	$(CC) -o $@ -c $< $(FLAG)

main: $(OBJECTS)
	@$(CC) -o $(NAME) $(FLAG) $(OBJECTS)

fast: $(OBJECTS)
	@$(CC) $(FLAG) -o $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(OBJECTS) $(NAME)

re: fclean all
