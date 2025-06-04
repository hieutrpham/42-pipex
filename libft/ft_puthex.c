/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:16:35 by trupham           #+#    #+#             */
/*   Updated: 2025/05/08 15:25:29 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	len_hex(unsigned long n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

static int	write_hex(unsigned long n, char c)
{
	char	*hex;
	int		i;

	if (c == 'x')
		hex = "0123456789abcdef";
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (n >= 16)
		write_hex(n / 16, c);
	i = ft_putchar(hex[n % 16]);
	if (i < 0)
		return (-1);
	return (i);
}

int	ft_puthex(unsigned long n, char c)
{
	if (write_hex(n, c) < 0)
		return (-1);
	return (len_hex(n));
}

int	ft_putptr(void *ptr)
{
	int	count;
	int	i;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 2;
	if (ft_putstr("0x") < 0)
		return (-1);
	i = ft_puthex((unsigned long)ptr, 'x');
	if (i < 0)
		return (-1);
	count += i;
	return (count);
}
