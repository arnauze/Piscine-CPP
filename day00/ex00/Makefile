OBJECTS = *.o
SRC = megaphone.cpp
NAME = megaphone
FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME):
	clang++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
