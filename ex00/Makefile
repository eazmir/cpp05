CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

LIB_NAME = libbureaucrat.a
LIB_SRCS = Bureaucrat.cpp
LIB_OBJS = $(LIB_SRCS:.cpp=.o)

MAIN_SRCS = main.cpp
MAIN_OBJS = $(MAIN_SRCS:.cpp=.o)

NAME = Bureaucrat

all: $(LIB_NAME) $(NAME)

$(LIB_NAME): $(LIB_OBJS)
	@ar rcs $(LIB_NAME) $(LIB_OBJS)

$(NAME): $(MAIN_OBJS) $(LIB_NAME)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJS) -L. -lbureaucrat -o $(NAME)

clean:
	rm -f $(MAIN_OBJS)
	@rm -f $(LIB_OBJS) 

fclean: clean
	rm -f $(NAME)
	@rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
