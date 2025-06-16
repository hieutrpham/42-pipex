/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:28:14 by trupham           #+#    #+#             */
/*   Updated: 2025/06/12 17:16:24 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_infile(char *infile)
{
	if (access(infile, R_OK) == 0)
		return (1);
	else
		perror(infile);
	return (0);
}

void	exit_error(char *err)
{
	if (ft_strncmp(err, "usage", 5) == 0)
		ft_putendl_fd("Usage: ./pipex 'infile' 'cmd1' 'cmd2' 'outfile'", STDERR_FILENO);
	else
		perror(err);
	exit(1);
}

void	exit_free(char **cmd, char *bin, int status)
{
	if (status == 127)
	{
		if (cmd[0])
		{
			ft_putstr_fd(cmd[0], STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putendl_fd("command not found", STDERR_FILENO);
		}
		else
			ft_putendl_fd("command not found", STDERR_FILENO);
	}
	else
		perror(cmd[0]);
	free_split(cmd);
	free(bin);
	exit(status);
}
