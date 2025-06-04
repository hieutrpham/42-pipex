/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:15:50 by trupham           #+#    #+#             */
/*   Updated: 2025/05/08 12:16:54 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	checktype(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'd' || c == 'i')
		return (ft_putint(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putuint(va_arg(*args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), c));
	else if (c == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	return (-1);
}

static int	t_print(const char *str, va_list *args, int *count)
{
	int	type;

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 0)
				return (-1);
			type = checktype(*str, args);
			if (type == -1)
				return (-1);
			else
				*count += type;
		}
		else
		{
			if (ft_putchar(*str) < 0)
				return (-1);
			(*count)++;
		}
		str++;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		type;

	if (write(1, "", 0) == -1)
		return (-1);
	if (!str)
		return (-1);
	count = 0;
	va_start(args, str);
	type = t_print(str, &args, &count);
	if (type == -1)
		return (va_end(args), -1);
	va_end(args);
	return (count);
}
