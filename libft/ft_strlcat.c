/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:38:50 by sangseo           #+#    #+#             */
/*   Updated: 2024/03/30 01:26:01 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	result;

	if (dst == 0 && size == 0)
		return (ft_strlen(src));
	i = 0;
	i = ft_strlen(dst);
	if (i >= size)
		return (ft_strlen(src) + size);
	result = ft_strlen((const char *)dst) + ft_strlen(src);
	j = 0;
	while (i + 1 < size && src[j] != 0)
	{
		dst[i++] = src[j++];
	}
	dst[i] = 0;
	return (result);
}
