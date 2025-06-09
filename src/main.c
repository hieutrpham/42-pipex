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
#include <fcntl.h>
#include <sys/types.h>

/*
 * check if the command includes '/'
 */
pid_t run_process1(char **av, char **env, int *pips)
{
	int fd1;

	if (!check_infile(av[1]))
		exit(EXIT_FAILURE);
	fd1 = open(av[1], O_RDONLY);
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
		close(fd1);
		dup2(pips[1], 1);
		close(pips[1]);
		char **cmd = build_exec_argv(av[2]);
		char *bin = get_binary_path(cmd[0], env);
		execve(bin, cmd, NULL);
		perror("execve");
	}
	return child1;
}

/* child2 process that read from child1 and give output to outfile
 * TODO:need to handle file permission
 */
pid_t run_process2(char **av, char **env, int *pips)
{
	int fd;
	pid_t child2;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	child2 = fork();
	if (child2 == -1)
	{
		perror("fork");
		exit(1);
	}
	if (child2 == 0)
	{
		close(pips[1]);
		dup2(pips[0], 0);
		dup2(fd, 1);
		close(fd);
		close(pips[0]);
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
		pid_t child2 = run_process2(av, env, pips);
		close(pips[1]);
		close(pips[0]);
		waitpid(child1, &status, 0);
		waitpid(child2, &status, 0);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
