NAME = form
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I./inc
OBJS = $(SRCS:.cpp=.o)
SRCS = $(wildcard src/*.cpp)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
