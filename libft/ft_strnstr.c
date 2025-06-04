/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:47:26 by trupham           #+#    #+#             */
/*   Updated: 2025/04/18 17:14:59 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;
	int	tmplen;

	if (!big)
		return (NULL);
	if (*little == 0 || !little)
		return ((char *)big);
	i = 0;
	while (big[i] && len)
	{
		j = 0;
		tmplen = len;
		while (tmplen && little[j] && big[i + j] && little[j] == big[i + j])
		{
			j++;
			tmplen--;
		}
		if (!little[j])
			return (&((char *)big)[i]);
		i++;
		len--;
	}
	return (NULL);
}
