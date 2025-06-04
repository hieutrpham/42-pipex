/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:12:52 by trupham           #+#    #+#             */
/*   Updated: 2025/04/18 17:14:59 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(int c)
{
	c = (char)c;
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	atoi;

	atoi = 0;
	i = 0;
	sign = 1;
	while (isspace(nptr[i]))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		atoi = atoi * 10 + (nptr[i] - '0');
		i++;
	}
	return (atoi * sign);
}
