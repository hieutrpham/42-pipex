/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:22:33 by trupham           #+#    #+#             */
/*   Updated: 2025/06/05 17:02:44 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

/* TODO: open infile. dup2 the fd to stdin. cmd1 will read from stdin now which is the fd
 * a function that takes fd1, dup2
 * check if the command includes '/'
 */

int	main(int ac, char **av, char **env)
{
	char	*cmd;

	if (ac == 5)
	{
		if (!check_infile(av[1]))
		{
			perror("infile");
			exit(1);
		}
		int fd1 = open(av[1], O_RDONLY);
		pid_t child = fork();
		if (child == -1)
		{
			perror("fork");
			exit(1);
		}
		if (child == 0)
		{
			close(0);
			dup2(fd1, 0);
			char **cmd = build_exec_argv(av[2]);
			char *bin = get_binary_path(cmd[0], env);
			execve(bin, cmd, NULL);
			perror("execve");
		}
		else
		{
			close(0);
			close(1);
			exit(0);
		}
	}
	return (0);
}
