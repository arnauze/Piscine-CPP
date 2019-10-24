OBJECTS = *.o
SRC = Account.class.cpp\
		tests.cpp
HEADER = Account.class.hpp
NAME = myBossIsADick
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	clang++ $(FLAGS) $(SRC) -o $(NAME) -I $(HEADER)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
