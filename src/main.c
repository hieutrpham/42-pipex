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

#include "../includes/pipex.h"
#include <stdlib.h>

// TODO: check error -1 for open, dup2
//
void	exit_error(char *err)
{
	perror(err);
	exit(1);
}

void print_debug(char **arr)
{
	int i = 0;
	
	while (arr[i])
	{
		fprintf(stderr, "DEBUG[x] arr[%d]: %s\n", i, arr[i]);
		i++;
	}
}
pid_t	run_process1(char **av, char **env, int *pips)
{
	int		fd1;
	pid_t	child1;
	char	**cmd;
	char	*bin;

	if (!check_infile(av[1]))
		return 1;
	fd1 = open(av[1], O_RDONLY);
	if (fd1 < 0)
		exit_error("infile");
	child1 = fork();
	if (child1 == -1)
		exit_error("fork");
	if (child1 == 0)
	{
		close(pips[0]);
		dup2(fd1, 0);
		dup2(pips[1], 1);
		close(fd1);
		close(pips[1]);
		cmd = build_exec_argv(av[2]);
		bin = get_binary_path(cmd[0], env);
		fprintf(stderr, "DEBUGPRINT[61]: main.c:57: bin=%s\n", bin);
		execve(bin, cmd, env);
		perror("DEBUG: execve");
		free_split(cmd);
		free(bin);
	}
	return (child1);
}

pid_t	run_process2(char **av, char **env, int *pips)
{
	int		fd;
	pid_t	child2;
	char	**cmd;
	char	*bin;

	child2 = fork();
	if (child2 == -1)
		exit_error("fork");
	if (child2 == 0)
	{
		fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
			exit_error("outfile");
		close(pips[1]);
		dup2(fd, 1);
		dup2(pips[0], 0);
		close(fd);
		close(pips[0]);
		cmd = build_exec_argv(av[3]);
		bin = get_binary_path(cmd[0], env);
		execve(bin, cmd, env);
		perror("execve");
		free_split(cmd);
		free(bin);
	}
	return (child2);
}

int	main(int ac, char **av, char **env)
{
	int		status[2];
	int		pips[2];
	pid_t	child1;
	pid_t	child2;

	if (ac != 5)
		return (1);
	if (pipe(pips) < 0)
		perror("pipe");
	child1 = run_process1(av, env, pips);
	child2 = run_process2(av, env, pips);
	close(pips[0]);
	close(pips[1]);
	waitpid(child1, &status[0], 0);
	waitpid(child2, &status[1], 0);
	if (WIFEXITED(status[1]))
		return (WEXITSTATUS(status[1]));
	return (1);
}
