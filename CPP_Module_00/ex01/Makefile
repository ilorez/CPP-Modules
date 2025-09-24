vpath %.cpp srcs
vpath %.hpp includes

NAME = phonebook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
INCDIR =  -I./includes
BUILD_DR = ./build/
HEADERS =  container.hpp Contact.hpp PhoneBook.hpp
SRCS = main.cpp  Contact.cpp PhoneBook.cpp

OBJS = $(addprefix $(BUILD_DR),$(SRCS:%.cpp=%.o))


# colors
green = \033[32m
reset = \033[0m

all: $(NAME)
	@echo "$(green)SUCCESS!!!$(reset)"

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(BUILD_DR)%.o: %.cpp $(HEADERS) | $(BUILD_DR) 
	$(CXX) $(CXXFLAGS) $(INCDIR) -c $< -o $@

$(BUILD_DR):
	mkdir -p $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

