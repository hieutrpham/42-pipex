/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:53:03 by trupham           #+#    #+#             */
/*   Updated: 2025/06/05 17:06:38 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
/*
 * @brief: function that takes the argv input from main and build an array of strings
 * that contain the command name and its arguments
 * @params: string variable
 * @return: array of strings
 */
char **build_cmd(char *av)
{
	char **temp;
	char **arr;
	
	temp = ft_split(av, ' ');
	if (!temp)
		return NULL;
	return arr;
}
