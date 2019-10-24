OBJECTS = *.o
SRC = replace.cpp
NAME = replace
FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME):
	clang++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

lldb:
	clang++ $(FLAGS) $(SRC) -o $(NAME) -g

re: fclean all
