/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:20:14 by trupham           #+#    #+#             */
/*   Updated: 2025/06/12 17:16:21 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>

char	*get_binary_path(char *cmd, char **env);
void	exit_error(void);
int		check_infile(char *infile);
char	**build_exec_argv(char *av);
void	free_split(char **arr);
void	exit_free(char **cmd, char *bin, int status);
#endif
