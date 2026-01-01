
# vpaths
vpath %.hpp includes
vpath %.cpp srcs

NAME = templates 

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I./includes  #-DDEBUG
RM = rm -rf
BUILD_DR = ./build/

HEADERS = whatever.hpp

F_SRCS = 

SRCS = main.cpp $(F_SRCS) 

OBJS = $(addprefix $(BUILD_DR),$(SRCS:%.cpp=%.o))

# colors
green = \033[32m
reset = \033[0m

all: $(NAME)
	@echo "$(green)SUCCESS!!!$(reset)"

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(BUILD_DR)%.o: %.cpp $(HEADERS) | $(BUILD_DR) 
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DR):
	mkdir -p $@

clean:
	$(RM) $(OBJS)
	$(RM) $(BUILD_DR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

