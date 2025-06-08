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

#include "pipex.h"
#include <sys/types.h>

/* TODO: open infile. dup2 the fd to stdin. cmd1 will read from stdin now which is the fd
 * a function that takes fd1, dup2
 * check if the command includes '/'
 */

/*
 * child1 process that read from infile
*/
pid_t run_process1(char **av, char **env, int *pips)
{
	if (!check_infile(av[1]))
	{
		perror("infile");
		exit(EXIT_FAILURE);
	}
	int fd1 = open(av[1], O_RDONLY);
	pid_t child1 = fork();
	if (child1 == -1)
	{
		perror("fork");
		exit(1);
	}
	if (child1 == 0)
	{
		close(pips[0]);
		dup2(fd1, 0);
		dup2(pips[1], 1);
		char **cmd = build_exec_argv(av[2]);
		char *bin = get_binary_path(cmd[0], env);
		execve(bin, cmd, NULL);
		perror("execve");
	}
	return child1;
}

/* child2 process that read from child1 and give output to outfile
 */
pid_t run_process2(char **av, char **env, int *pips)
{
	pid_t child2 = fork();
	if (child2 == -1)
	{
		perror("fork");
		exit(1);
	}
	if (child2 == 0)
	{
		close(pips[1]);
		dup2(pips[0], 0);
		char **cmd = build_exec_argv(av[3]);
		char *bin = get_binary_path(cmd[0], env);
		execve(bin, cmd, NULL);
		perror("execve");
	}
	return child2;
}

int	main(int ac, char **av, char **env)
{
	char	*cmd;
	int status;
	int pips[2];
	if (ac == 5)
	{
		if (pipe(pips) < 0)
			perror("pipe");
		pid_t child1 = run_process1(av, env, pips);
		close(pips[1]);
		pid_t child2 = run_process2(av, env, pips);
		waitpid(child1, &status, 0);
		close(pips[0]);
		waitpid(child2, &status, 0);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
