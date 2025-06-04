/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:37:54 by trupham           #+#    #+#             */
/*   Updated: 2025/04/18 14:13:36 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	sum;

	sum = 0;
	while (n)
	{
		sum = *(unsigned char *)s1 - *(unsigned char *)s2;
		if (sum != 0)
			break ;
		n--;
		s1++;
		s2++;
	}
	return (sum);
}
