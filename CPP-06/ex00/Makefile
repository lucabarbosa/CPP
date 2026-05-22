NAME = converter

CXX      = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

GREEN  = \033[0;32m
RED    = \033[0;31m
BLUE = \033[0;36m
YELLOW = \033[0;33m
RESET  = \033[0m

SRC      := $(shell find . -type f -name "*.cpp")
OBJS_DIR  = obj
OBJS     := $(patsubst %.cpp, $(OBJS_DIR)/%.o, $(notdir $(SRC)))

all: $(NAME)

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)🚀 Binary $(YELLOW)$@$(GREEN) created!$(RESET)\n"

clean:
	@rm -rf $(OBJS) $(OBJS_DIR)
	@printf "$(BLUE)🧹 Object and folder removed.$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)💥 Binaries and outfiles removed.$(RESET)\n"

re: fclean all

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re valgrind