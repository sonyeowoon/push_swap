/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:47:34 by sangseo           #+#    #+#             */
/*   Updated: 2024/03/30 01:25:40 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	arrcnt(char *s, char c)
{
	int	flg;
	int	cnt;

	flg = 0;
	cnt = 0;
	while (*s)
	{
		if (flg == 0 && *s != c)
			cnt++;
		if (*s != c)
			flg = 1;
		else if (*s == c)
			flg = 0;
		s++;
	}
	return (cnt);
}

static int	arrstrlen(const char *s, char c)
{
	int	flg;
	int	cnt;

	flg = 0;
	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			flg = 1;
			cnt++;
		}
		if (flg == 1 && *s == c)
			return (cnt);
		s++;
	}
	return (cnt);
}

static int	insert_str(const char *s, char c, int i, char **arr)
{
	int	flg;
	int	j;
	int	cnt;

	flg = 0;
	j = 0;
	cnt = 0;
	while (!(flg == 1 && *s == c) && *s != 0)
	{
		if (*s != c)
		{
			arr[i][j++] = *s;
			flg = 1;
		}
		s++;
		cnt++;
	}
	arr[i][j++] = 0;
	return (cnt);
}

static void	ft_free(char **arr, int i)
{
	while (i >= 0)
	{
		free(*(arr + i));
		i--;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		arrlen;
	int		flg;

	arrlen = arrcnt((char *)s, c);
	arr = (char **)malloc(sizeof(char *) * (arrlen + 1));
	if (!arr)
		return (0);
	flg = 0;
	i = 0;
	while (i < arrlen)
	{
		*(arr + i) = (char *)malloc(sizeof(char) * (arrstrlen(s, c) + 1));
		if (!(*(arr + i)))
			flg = 1;
		s = s + insert_str(s, c, i++, arr);
	}
	arr[i] = 0;
	if (flg == 1)
	{
		ft_free(arr, i);
		return (0);
	}
	return (arr);
}
