CC=cc -Wall -Werror Wextra
all:
	@cc *.c *.h libft/libft.a -g
	@./a.out README.md "cat" "grep 4 -C 3" outfile

debug:
	CC+=-g

asan:
	CC+=-fsanitize=address
