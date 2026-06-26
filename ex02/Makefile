NAME = PmergeMe
CC = c++
FLAGS = -Wall -Wextra -Werror $(INCLUDES) $(STD) -MMD -MP -g
STD = -std=c++98

SRC_DIR = src/
INC_DIR = inc/
OBJ_DIR = .obj/

SRC = main.cpp PmergeMe.cpp

INCLUDES = -I$(INC_DIR)
OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.cpp=%.o))
DEPS = $(OBJ:%.o=%.d)

.PHONY : all
all : $(NAME)

.PHONY : clean
clean :
	rm -rf $(OBJ_DIR)

.PHONY : fclean
fclean : clean
	rm -rf $(NAME)

.PHONY : re
re : fclean
	$(MAKE) all

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $@

-include $(DEPS)

