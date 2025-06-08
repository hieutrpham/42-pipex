CC=cc -Wall -Werror Wextra
all:
	@cc *.c *.h libft/libft.a -g
	@./a.out README.md "cat" "wc" "test.txt"

debug:
	CC+=-g

asan:
	CC+=-fsanitize=address
