/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:32:25 by trupham           #+#    #+#             */
/*   Updated: 2025/04/23 15:49:25 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_len(int n)
{
	int		len;
	long	tmp;

	tmp = n;
	len = 0;
	if (tmp < 0)
	{
		tmp = -tmp;
		len++;
	}
	while (tmp)
	{
		len++;
		tmp = tmp / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		index;
	long	tmp;

	tmp = n;
	if (tmp == 0)
		return (ft_strdup("0"));
	index = ft_len(n) - 1;
	str = ft_calloc(index + 2, sizeof(char));
	if (!str)
		return (NULL);
	if (tmp < 0)
	{
		str[0] = '-';
		tmp = -tmp;
	}
	while (tmp > 0)
	{
		str[index] = (tmp % 10) + '0';
		index--;
		tmp = tmp / 10;
	}
	return (str);
}
