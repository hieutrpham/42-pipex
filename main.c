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
#include <assert.h>

int	main(int ac, char **av, char **env)
{
	char	*cmd;

	if (ac == 5)
	{
		cmd = getcmd("xargs", env);
		// fprintf(stderr, "DEBUGPRINT[50]: main.c:89: cmd=%s\n", cmd);
		free(cmd);
		char **arr = build_cmd(av[2]);
		int i = 0;
		char *cmd = getcmd(arr[0], env);
		// fprintf(stderr, "DEBUGPRINT[34]: main.c:25: cmd=%s\n", cmd);
		execve(cmd, arr, NULL);
		perror("execve");
	}
	return (0);
}
