/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:00:29 by trupham           #+#    #+#             */
/*   Updated: 2025/04/23 18:08:11 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	tmp;

	tmp = (long)n;
	if (tmp < 0)
	{
		ft_putchar_fd('-', fd);
		tmp = -tmp;
	}
	if (tmp > 9)
		ft_putnbr_fd(tmp / 10, fd);
	ft_putchar_fd((tmp % 10) + '0', fd);
}
