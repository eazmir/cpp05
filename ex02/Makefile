CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Form

DIR_OBJ = obj
DIR_SRC = src
DIR_INC = include
DIR_MIN = main

SRCS = \
	$(DIR_MIN)/main.cpp \
	$(DIR_SRC)/Form.cpp \
	$(DIR_SRC)/Bureaucrat.cpp\
	$(DIR_SRC)/PresidentialPardonForm.cpp\
	$(DIR_SRC)/RobotomyRequestForm.cpp\
	$(DIR_SRC)/ShrubberyCreationForm.cpp

OBJS = $(SRCS:$(DIR_SRC)/%.cpp=$(DIR_OBJ)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.cpp
	@mkdir -p $(DIR_OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(DIR_OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re

