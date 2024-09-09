/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:51:11 by sangseo           #+#    #+#             */
/*   Updated: 2024/03/26 07:16:02 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*arr;
	size_t			i;

	if (n == 0)
		return (dest);
	if (dest == (void *)0 && src == 0)
		return ((void *)0);
	arr = (unsigned char *)dest;
	i = 0;
	if (src >= dest)
	{
		while (i < n)
		{
			arr[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (i++ < n)
			arr[n - i] = ((unsigned char *)src)[n - i];
	}
	return ((void *)arr);
}
