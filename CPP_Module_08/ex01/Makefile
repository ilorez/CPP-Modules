
vpath %.hpp includes

NAME = span 

HEADERS = Span.hpp
SRCS = Span.cpp main.cpp
OBJS = $(SRCS:%.cpp=%.o)
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf
CXX = c++

all: ${NAME}
	@echo "SUCCESS!"

${NAME}: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)



%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean clean

.PHONY: all clean fclean re



