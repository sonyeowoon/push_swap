/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:32:17 by sangseo           #+#    #+#             */
/*   Updated: 2024/03/26 02:46:12 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*arr;

	arr = (unsigned char *)dest;
	i = 0;
	if (dest == 0 && src == 0)
		return ((void *)0);
	while (i < n)
	{
		arr[i] = ((unsigned char *)src)[i];
		i++;
	}
	return ((void *)arr);
}
