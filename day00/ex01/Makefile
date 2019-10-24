OBJECTS = *.o
SRC = Contact.class.cpp\
		Journal.class.cpp\
		main.cpp
HEADER = header.hpp
NAME = phonebook
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	clang++ $(FLAGS) $(SRC) -o $(NAME) -I $(HEADER)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
