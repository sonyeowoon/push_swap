/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 04:12:05 by sangseo           #+#    #+#             */
/*   Updated: 2024/11/18 12:02:37 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mini_sort(t_node **a, int a_size)
{
	if (a_size == 3 && !(chk_ascending(*a)))
		ft_swap("sa", a);
	min_to_top(a, a_size);
}

static void	pb_pivot(t_node **a, t_node **b)
{
	int	pivot[4];

	find_pivot(a, pivot);
	divide_pivot(a, b, pivot);
}

void	pa_all(t_node **a, t_node **b, int *a_size)
{
	int	*b_size;
	int	min_idx;

	b_size = (int *)malloc(sizeof(int));
	*b_size = ft_lstsize(*b);
	while (*b)
	{
		min_idx = get_paidx(*a, *b, *a_size, *b_size);
		pa_min(a, b, min_idx);
		(*a_size)++;
		(*b_size)--;
	}
	free(b_size);
}

void	ft_sorting(t_node *a, t_node *b)
{
	int	a_size;

	pb_pivot(&a, &b);
	a_size = ft_lstsize(a);
	if (a_size <= 3)
		mini_sort(&a, a_size);
	pa_all(&a, &b, &a_size);
	min_to_top(&a, ft_lstsize(a));
	stack_free(a);
}
