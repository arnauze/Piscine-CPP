OBJECTS = *.o
SRC = Fixed.class.cpp\
		Stack.class.cpp\
		main.cpp
NAME = eval_expr
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	clang++ $(FLAGS) $(SRC) -o $(NAME)

lldb:
	clang++ $(FLAGS) $(SRC) -o $(NAME) -g

cleanlldb:
	rm -rf $(NAME).dSYM

clean:
	rm -f $(OBJECTS)

fclean: clean cleanlldb
	rm -f $(NAME)

re: fclean all
