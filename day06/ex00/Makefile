OBJECTS = *.o
SRC = main.cpp
FLAGS = -Wall -Wextra -Werror
NAME = extract

all: $(NAME)

$(NAME):
	clang++ $(FLAGS) $(SRC) -o $(NAME) 

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
