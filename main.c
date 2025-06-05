/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:21:26 by trupham           #+#    #+#             */
/*   Updated: 2025/06/04 17:03:27 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <unistd.h>

int check_infile(char *infile)
{
	if (access(infile, R_OK) == 0)
		return 1;
	else
		perror("infile");
	return 0;
}
int check_outfile(char *outfile)
{
	if (access(outfile, W_OK) == 0)
		return 1;
	else
		perror("outfile");
	return 0;
}
/* WARN: need to free returned string
 */
char *ft_getenv(char **env, char *name)
{
	int i = 0;
	int len = 0;

	len = ft_strlen(name);
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0)
			return ft_substr(env[i], len+1, ft_strlen(env[i]) - len - 1);
		i++;
	}
	return NULL;
}

void free_split(char **arr)
{
	int i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

/* @brief takes a command string and search for binary file in PATH
 * @params char **env: array of strings containing environment variables
 * @params char* cmd: ls, cat, etc.
 * @return char*: the whole path to the command: /usr/bin/cat
 */
char *getcmd(char *cmd, char **env)
{
	char *path;
	char **arr;
	int i = 0;
	char *tmp_cmd;
	char *full_cmd;

	path = ft_getenv(env, "PATH");
	arr = ft_split(path, ':');
	if (!arr)
		return (free(path), NULL);
	free(path);
	while (arr[i])
	{
		tmp_cmd = ft_strjoin(arr[i], "/");
		if (!tmp_cmd)
			return NULL;
		full_cmd = ft_strjoin(tmp_cmd, cmd);
		if (!full_cmd)
			return (free(tmp_cmd), NULL);
		free(tmp_cmd);
		if (access(full_cmd, X_OK) == 0)
			return (free_split(arr), full_cmd);
		else
			free(full_cmd);
		i++;
	}
	free_split(arr);
	return NULL;
}

int main(int ac, char **av, char **env)
{
	char *cmd;

	if (ac == 5)
	{
		cmd = getcmd("awk", env);
		fprintf(stderr, "DEBUGPRINT[50]: main.c:89: cmd=%s\n", cmd);
		free(cmd);
	}
	return 0;
}
