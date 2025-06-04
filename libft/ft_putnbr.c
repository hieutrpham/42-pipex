/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:33:41 by trupham           #+#    #+#             */
/*   Updated: 2025/05/07 14:20:03 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	write_int(int n)
{
	long	tmp;
	int		i;

	i = 0;
	tmp = (long)n;
	if (tmp < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		tmp = -tmp;
	}
	if (tmp > 9)
		write_int(tmp / 10);
	i = ft_putchar((tmp % 10) + '0');
	if (i < 0)
		return (-1);
	return (i);
}

static int	write_uint(unsigned int n)
{
	long	tmp;
	int		i;

	i = 0;
	tmp = (long)n;
	if (tmp > 9)
	{
		i = write_int(tmp / 10);
		if (i < 0)
			return (-1);
	}
	if (ft_putchar((tmp % 10) + '0') < 0)
		return (-1);
	return (i);
}

int	ft_putint(int n)
{
	if (write_int(n) < 0)
		return (-1);
	return (ft_ilen(n));
}

int	ft_putuint(unsigned int n)
{
	if (write_uint(n) < 0)
		return (-1);
	return (ft_ulen(n));
}
