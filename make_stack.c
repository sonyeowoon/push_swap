/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:57:56 by sangseo           #+#    #+#             */
/*   Updated: 2024/08/13 20:16:37 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chk_int(long long n)
{
	if (n == (long long)((int)n))
		return (1);
	return (0);
}

static int	ft_chkspace(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			return (1);
		str++;
	}
	return (0);
}

static long long	ft_bigatoi(char *str)
{
	long long	ngtv;
	long long	n;

	ngtv = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			ngtv = -1;
		str++;
	}
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + *str - '0';
		str++;
	}
	return (ngtv * n);
}

static int	cnt_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !(ft_isspace(str[i])))
		i++;
	return (i);
}

t_node	*make_stack(char **av)
{
	t_node		*a;
	t_node		*new;
	long long	d;

	a = 0;
	while (*(++av))
	{
		while (**av)
		{
			while (ft_isspace(**av))
				(*av)++;
			if (**av == '\0')
				break ;
			d = ft_bigatoi(*av);
			if (chk_int(d))
			{
				new = ft_lstnew((int)d);
				ft_lstadd_back(&a, new);
			}
			else
				ft_error(a);
			*av += cnt_digits(*av);
		}
	}
	return (a);
}
