/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:40:45 by sangseo           #+#    #+#             */
/*   Updated: 2024/03/26 02:26:25 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*arr;
	unsigned int	i;

	if (start >= ft_strlen((const char *)s))
	{
		arr = (char *)malloc(sizeof(char) * 1);
		if (!arr)
			return (0);
		arr[0] = 0;
		return (arr);
	}
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	i = 0;
	while (s[start] != 0 && i < len)
	{
		arr[i++] = s[start++];
	}
	arr[i] = 0;
	return (arr);
}
