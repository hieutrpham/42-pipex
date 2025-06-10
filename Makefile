CC = cc -Wall -Werror -Wextra
NAME = pipex
SRC_PATH = src/
OBJ_PATH = obj/
INCLUDE = -I.
LIBFT_PATH = ./libft/
TEST_PATH = tests/

SRC = check_file.c  \
	  main.c \
	  parse_cmd.c \
	  parse_file.c \

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME) libft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIBFT_PATH)libft.a $(INCLUDE)

libft:
	make -C $(LIBFT_PATH)

test: $(NAME)
	$(TEST_PATH)test

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug:
	make CC="$(CC) -g" re

asan:
	make CC="$(CC) -fsanitize=address" re

.PHONY: all re clean fclean debug asan
