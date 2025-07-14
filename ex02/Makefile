NAME = use_form
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I./inc -fsanitize=address
OBJS = $(SRCS:.cpp=.o)
SRCS = $(wildcard src/*.cpp)
OTHER = $(wildcard *_shrub*)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OTHER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
