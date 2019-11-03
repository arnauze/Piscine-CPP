OBJECTS = *.o
SRC = main.cpp
FLAGS = -Wall -Wextra -Werror
NAME = a.out

all: $(NAME)

$(NAME):
	clang++ $(FLAGS) $(SRC) -o $(NAME) 

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
