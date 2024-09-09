/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:41:00 by sangseo           #+#    #+#             */
/*   Updated: 2024/03/30 01:00:30 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	size_t	t;

	t = size * nmemb;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > t / size)
		return (0);
	arr = malloc(size * nmemb);
	if (!(arr))
		return (0);
	ft_bzero(arr, nmemb * size);
	return (arr);
}
