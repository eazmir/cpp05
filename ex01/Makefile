CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Form

DIR_SRC = src
DIR_INC = include

SRCS = \
	$(DIR_SRC)/main.cpp \
	$(DIR_SRC)/Form.cpp \
	$(DIR_SRC)/Bureaucrat.cpp

OBJS = $(SRCS:.cpp=.o)

# ===== RULES =====

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(DIR_INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

