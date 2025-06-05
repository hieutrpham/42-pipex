all:
	cc *.c *.h libft/libft.a -g && ./a.out infile "ls -l -a" "xargs du -h" outfile
