/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:26:04 by trupham           #+#    #+#             */
/*   Updated: 2025/04/19 16:26:05 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	if (n && size > SIZE_MAX / n)
		return (NULL);
	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	while (i < n * size)
		ptr[i++] = 0;
	return (ptr);
}
