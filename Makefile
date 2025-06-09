CC=cc -Wall -Werror Wextra
all:
	@cc *.c *.h libft/libft.a -g

debug:
	CC+=-g

asan:
	CC+=-fsanitize=address
