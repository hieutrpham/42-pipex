/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:20:14 by trupham           #+#    #+#             */
/*   Updated: 2025/06/05 17:01:33 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

#define PIPEX_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "libft/libft.h"
#include <fcntl.h>

char	*get_binary_path(char *cmd, char **env);
int	check_infile(char *infile);
int	check_outfile(char *outfile);
char **build_exec_argv(char *av);
#endif

