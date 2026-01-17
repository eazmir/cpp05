MAKEFLAGS += --no-print-directory

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Intern

DIR_MIN = main
DIR_SRC = src
DIR_OBJ = obj
PRE_DIR = $(DIR_SRC)/ex02

LIBPREVOIS_EX = $(PRE_DIR)/libprevious_ex.a

SRCS = \
	$(DIR_MIN)/main.cpp \
	$(DIR_SRC)/Intern.cpp

OBJS = $(SRCS:%.cpp=$(DIR_OBJ)/%.o)

all: $(NAME)
$(NAME): $(OBJS) $(LIBPREVOIS_EX)
	@$(CXX) $(CXXFLAGS) $(OBJS) $(LIBPREVOIS_EX) -o $(NAME)
	@echo "  Compiler: $(CXX)"
	@echo "  Standard: C++98"
	@echo "  Flags: $(CXXFLAGS)"
	
$(DIR_OBJ)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(LIBPREVOIS_EX):
	@make -C $(PRE_DIR)

clean:
	@rm -rf $(DIR_OBJ)
	@make -C $(PRE_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRE_DIR) fclean
	@rm -f *_shrubbery 

re: fclean all

.PHONY: all clean fclean re
