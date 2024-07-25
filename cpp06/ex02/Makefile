NAME	= base

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD

HEADERS = $(wildcard *.hpp)

SRC		= $(wildcard *.cpp)

OBJ		= $(SRC:.cpp=.o)


-include $(wildcard *.d)

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJ) -o $@


%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.d

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean