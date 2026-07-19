NAME    = Animal
CXX      = c++
CXXFLAGS  = -Wall -Wextra -Werror -g -std=c++98
OBJ_DIR = .obj
SRC     = Animal.cpp WrongAnimal.cpp Cat.cpp Dog.cpp WrongCat.cpp main.cpp Brain.cpp
OBJ     = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re