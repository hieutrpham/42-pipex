all:
	@cc *.c *.h libft/libft.a -g
	@./a.out README.md "cat" "xargs du -h" outfile
