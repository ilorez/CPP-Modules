
NAME = woow_phonebook

SRCS = PhoneBook.cpp
OBJS = $(SRCS:%.cpp=%.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = g++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

