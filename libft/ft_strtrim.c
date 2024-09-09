/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:09:31 by sangseo           #+#    #+#             */
/*   Updated: 2024/03/29 19:36:33 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	startcmp(char *temp, char const *set)
{
	int	i;

	i = 0;
	while (temp[i] && is_set(temp[i], set))
		i++;
	return (i);
}

static int	endcmp(char *temp, size_t idx, char const *set)
{
	while (is_set(temp[idx], set) == 1 && idx > 0)
	{
		idx--;
	}
	return (idx + 1);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*temp;
	size_t	i;
	char	*arr;
	size_t	arrlen;

	temp = (char *)s;
	temp += startcmp(temp, set);
	if (*temp == 0)
		return (ft_strdup(""));
	arrlen = endcmp(temp, ft_strlen((const char *)temp) - 1, set);
	arr = (char *)malloc(sizeof(char) * (arrlen + 1));
	if (!arr)
		return (0);
	i = 0;
	while (temp[i] && i < arrlen)
	{
		arr[i] = temp[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}
