CC = cc -Wall -Werror -Wextra -MMD -MP
NAME = pipex
SRC_PATH = src/
OBJ_PATH = obj/
INCLUDE = -I. -Iincludes/
LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a
TEST_PATH = tests/

GREEN := \033[32m
RESET := \033[0m

SRC = main.c \
	  parser.c \
	  utils.c \

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
DEP = $(addprefix $(OBJ_PATH), $(SRC:.c=.d))

all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $^ -o $@ $(LIBFT)
	@printf "$(GREEN)$(NAME) created successfully!$(RESET)\n"

$(LIBFT):
	make -C $(LIBFT_PATH)

test: all
	$(TEST_PATH)test

clean:
	rm -rf $(OBJ_PATH) $(DEP)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

debug:
	make CC="$(CC) -g" re

asan:
	make CC="$(CC) -fsanitize=address" re

.PHONY: all re clean fclean debug asan

-include $(DEP)
