/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:17:21 by sangseo           #+#    #+#             */
/*   Updated: 2024/11/17 23:26:03 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bn(t_node *b, int idx)
{
	int	i;

	i = 0;
	while (i++ < idx)
		b = b->next;
	return (b->n);
}
/*
int	find_nextmax_node(t_node *a, int max_idx, int max_top)
{
	int	i;
	int next_max;
	int	next_max_idx;

	i = 0;
	while ((max_idx < max_top && i <= max_idx) || (i >= max_top && i <= max_idx))
	{
		a = (*a).next;
		i++;
	}
	next_max = (*a).n;
	next_max_idx = i;
	while (a)
	{
		if (!(i >= max_top && i <= max_idx) && (next_max < (*a).n))
		{
			next_max = (*a).n;
			next_max_idx = i;
		}
		a = (*a).next;
		i++;
	}
	return (next_max_idx);
}

void	next_max_top(int *a_size, t_node **a, int *max_idx, int *max_top)
{
	int	next_max_idx;

	next_max_idx = find_nextmax_node(*a, *max_idx, *max_top);
	if (next_max_idx > (*a_size - next_max_idx))
	{
		next_max_idx = *a_size - next_max_idx;
		while (next_max_idx--)
			ft_reverse_rotate("rra", a), (*max_idx)++, (*max_top)++;
		over_idx_handling(max_idx, *a_size), over_idx_handling(max_top, *a_size);
	}
	else
	{
		while (next_max_idx--)
			ft_rotate("ra", a), (*max_idx)--, (*max_top)--;
		over_idx_handling(max_idx, *a_size), over_idx_handling(max_top, *a_size);
	}
}

void	over_idx_handling(int *idx, int size)
{
	if (*idx >= size)
		*idx = *idx - size;
	else if (*idx < 0)
		*idx = size + *idx;
}

int	swap_flg(int a_size, int max_top, int next_max_idx)
{
	if (max_top > next_max_idx && (max_top - next_max_idx == 2))
		return (1);
	else
	{
		max_top -= 2;
		next_max_idx -= 2;
		over_idx_handling(&max_top, a_size), over_idx_handling(&next_max_idx, a_size);
		if (max_top - next_max_idx == 2)
			return (1);
	}
	return (0);
}
*/
