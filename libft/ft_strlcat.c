/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:35:02 by trupham           #+#    #+#             */
/*   Updated: 2025/04/17 11:35:02 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dest >= size)
		return (len_src + size);
	while (dst[i])
		i++;
	while (src[j] && j < size - len_dest - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (len_src + len_dest);
}
