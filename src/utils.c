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
		ft_putendl_fd(strerror(errno), 2);
	return (0);
}

void	exit_error(void)
{
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}

void	exit_free(char **cmd, char *bin, int status)
{
	ft_putendl_fd(strerror(errno), 2);
	free_split(cmd);
	free(bin);
	exit(status);
}
