CC = cc -Wall -Werror -Wextra
NAME = pipex
SRC_PATH = src/
OBJ_PATH = obj/
INCLUDE = -I.
LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a
TEST_PATH = tests/

GREEN    := \033[32m
RESET    := \033[0m

SRC = main.c \
	  parser.c \
	  utils.c \

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $@ $(LIBFT) $(INCLUDE)
	@printf "$(GREEN)$(NAME) created successfully!$(RESET)\n"

$(LIBFT):
	make -C $(LIBFT_PATH)

test: all
	$(TEST_PATH)test

clean:
	rm -rf $(OBJ_PATH)
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
