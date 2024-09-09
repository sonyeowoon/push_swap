/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 04:12:05 by sangseo           #+#    #+#             */
/*   Updated: 2024/08/14 18:47:02 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static int	choose_sorting(t_node *a, int a_size, int max_idx, int max_top)
{
	int	next_max_idx;
	int	min_sort_cnt;
	int	max_sort_cnt;
	int	flg;

	flg = 0;
	min_sort_cnt = find_min_node(a);
	if (min_sort_cnt > (a_size - min_sort_cnt))
		min_sort_cnt = a_size - min_sort_cnt;
	next_max_idx = find_nextmax_node(a, max_idx, max_top);
	flg = swap_flg(a_size, max_top, next_max_idx);
	max_top -= next_max_idx;
	if (max_top < 0)
		max_top = a_size + max_top;
	if (max_top > (a_size - max_top))
		max_top = a_size - max_top + 1;
	if (next_max_idx > (a_size - next_max_idx))
		next_max_idx = a_size - next_max_idx;
	max_sort_cnt = next_max_idx + max_top;
	if (flg)
		max_sort_cnt = next_max_idx;
	if (min_sort_cnt <= max_sort_cnt)
		return (1);
	return (0);
}

static void	min_pb(int *a_size, t_node **a, t_node **b, int	*max_idx, int *max_top)
{
	min_to_top(a, *a_size, max_idx, max_top);
	ft_push("pb", a, b);
	if (*max_idx < 0)
		*max_idx = *a_size + *max_idx;
	else if (*max_idx >= *a_size)
		*max_idx -= *a_size;
	if (*max_top < 0)
		*max_top = *a_size + *max_top;
	else if (*max_top >= *a_size)
		*max_top -= *a_size;
	(*a_size)--;
	(*max_idx)--;
	(*max_top)--;
}

static void	max_sort(int *a_size, t_node **a, t_node **b, int *max_idx, int *max_top)
{
	int	tmp;

	next_max_top(a_size, a, max_idx, max_top);
	if (swap_flg(*a_size, *max_top, 0))
	{
		ft_swap("sa", a), (*max_top = 1);
	}
	else
	{
		ft_push("pb", a, b), (*a_size)--, (*max_idx)--, (*max_top)--;
		if (*max_top > (*a_size - *max_top))
		{
			tmp = *a_size - *max_top;
			while (tmp--)
				ft_reverse_rotate("rra", a), (*max_idx)++, (*max_top)++;
		}
		else
		{
			tmp = *max_top;
			while (tmp--)
				ft_rotate("ra", a), (*max_idx)--, (*max_top)--;
		}
		over_idx_handling(max_idx, *a_size), over_idx_handling(max_top, *a_size);
		ft_push("pa", b, a), (*a_size)++, (*max_idx)++, (*max_top = 0);
	}
}

void	ft_sorting(t_node *a, t_node *b)
{
	int	a_size;
	int	max_idx;
	int	max_top;

	a_size = ft_lstsize(a);
	max_idx = find_max_node(a);
	max_top = max_idx;
	while (!(chk_ascending(a)))
	{
		if (choose_sorting(a, a_size, max_idx, max_top))
			min_pb(&a_size, &a, &b, &max_idx, &max_top);
		else
			max_sort(&a_size, &a, &b, &max_idx, &max_top);
	}
	min_to_top(&a, a_size, &max_idx, &max_top);
	while (b != NULL)
		ft_push("pa", &b, &a);
}
*/

static void    pb_pivot(t_node **a, t_node **b)
{
    int pivot[4];
    int i;

    i = 0;
    find_pivot(a, pivot);
	divide_pivot(a, b, pivot);
}

void	ft_sorting(t_node *a, t_node *b)
{
	if (!(chk_ascending(a)))
	{
		pb_pivot(&a, &b);
	}
	ft_printf("----------");
	ft_printf("A stack\n");
	while (a)
	{
		ft_printf("%d\n", (*a).n);
		a = (*a).next;
	}
	ft_printf("----------");
	ft_printf("B stack\n");
	while (b)
	{
		ft_printf("%d\n", (*b).n);
		b = (*b).next;
	}
}