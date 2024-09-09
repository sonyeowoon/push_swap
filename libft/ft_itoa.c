/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:45:04 by sangseo           #+#    #+#             */
/*   Updated: 2024/03/26 02:32:06 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strcnt(int n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
		cnt++;
	if (n > 0)
		n = -n;
	while (n <= -1)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static void	insert_str(char *s, int n, int cnt)
{
	if (n < 0)
	{
		n = -n;
	}
	while (cnt)
	{
		cnt--;
		s[cnt] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	int		cnt;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	cnt = strcnt(n);
	s = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!s)
		return (0);
	insert_str(s, n, cnt);
	if (n < 0)
		s[0] = '-';
	s[cnt] = 0;
	return (s);
}
