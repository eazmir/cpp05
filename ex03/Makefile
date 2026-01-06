CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=-98

NAME = Intern
DIR_MIN = main
DIR_OBJ = obj 
DIR_SRC = src
PRE_DIR = /ex02

LIBPREVOIS_EX = $(PRE_DIR)/libprevious_ex.a

SRCS= \
	$(DIR_MIN)/main.cpp \
	$(DIR_SRC)/Intern.cpp\

OBJS=$(SRCS:=.cpp)

all : $(NAME)

$(NAME): $(OBJS) $(LIBPREVOIS_EX)
	$(CXX) $(CXXFLAGS) $(LIBPREVOIS_EX) -o $(NAME)

$(LIBPREVOIS_EX) $(PRE_DIR)
	@make -C $(PRE_DIR)

clean:
	@rm -f $(OBJS)
	@make -C $(PRE_DIR) clean

fclean:clean
	@rm -f $(NAME)
	@make -C $(PRE_DIR) fclean

re:fclean all

.PHONY: fclean all clean 
