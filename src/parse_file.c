/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:21:26 by trupham           #+#    #+#             */
/*   Updated: 2025/06/05 16:28:45 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
 * @brief: function that find the environment variable given it's name.
 * @params: env variable passed in from main and the name of the var
 * @return: the string containing the environment variable. eg. "PATH=usr/bin:usr/.local/bin"
 */
static char	*ft_getenv(char **env, char *name)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(name);
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0)
			return (ft_substr(env[i], len + 1, ft_strlen(env[i]) - len - 1));
		i++;
	}
	return (NULL);
}

static void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static char *norm_getcmd(char **arr, char *cmd)
{
	int i;
	char	*tmp_cmd;
	char	*full_cmd;

	i = 0;
	while (arr[i])
	{
		tmp_cmd = ft_strjoin(arr[i], "/");
		if (!tmp_cmd)
			return (NULL);
		full_cmd = ft_strjoin(tmp_cmd, cmd);
		if (!full_cmd)
			return (free(tmp_cmd), NULL);
		free(tmp_cmd);
		if (access(full_cmd, X_OK) == 0)
			return (full_cmd);
		else
			free(full_cmd);
		i++;
	}
	return NULL;
}
/*
 * @brief: takes a command string and search for binary file in PATH
 * @params: name of the command eg: ls, cat, etc.
 * @params: array of strings containing environment variables
 * @return: the whole path to the command: /usr/bin/cat
 */
char	*get_binary_path(char *cmd, char **env)
{
	char	*path;
	char	**arr;
	int		i;
	char	*full_cmd;

	i = 0;
	path = ft_getenv(env, "PATH");
	if (!path)
		return NULL;
	arr = ft_split(path, ':');
	if (!arr)
		return (free(path), NULL);
	free(path);
	full_cmd = norm_getcmd(arr, cmd);
	if (!full_cmd)
		return (free(full_cmd), NULL);
	return (free_split(arr), full_cmd);
}
