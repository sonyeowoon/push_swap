/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:13:58 by sangseo           #+#    #+#             */
/*   Updated: 2024/03/26 02:14:49 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	int		flg;

	flg = 0;
	while (*s)
	{
		if (*s == (char)c)
		{
			result = (char *)s;
			flg = 1;
		}
		s++;
	}
	if (c == 0 && *s == 0)
		return ((char *)s);
	if (flg == 1)
		return ((char *)result);
	else
		return (0);
}
