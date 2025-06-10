/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:28:14 by trupham           #+#    #+#             */
/*   Updated: 2025/06/05 16:28:23 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_infile(char *infile)
{
	if (access(infile, R_OK) == 0)
		return (1);
	else
		perror("infile");
	return (0);
}

int	check_outfile(char *outfile)
{
	if (access(outfile, W_OK) == 0)
		return (1);
	else
		perror("outfile");
	return (0);
}
