/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:57:59 by trupham           #+#    #+#             */
/*   Updated: 2025/04/16 11:58:17 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_tmp;
	const unsigned char	*src_tmp;

	dest_tmp = dest;
	src_tmp = src;
	if (src >= dest)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			*(dest_tmp + n - 1) = *(src_tmp + n - 1);
			n--;
		}
	}
	return (dest_tmp);
}
