/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_flg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:47:14 by sangseo           #+#    #+#             */
/*   Updated: 2024/11/18 15:07:33 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_double(t_node **a, t_node **b, int min_idx, int flg)
{
	int	i;
	int	temp;

	i = 0;
	if (flg == 1)
	{
		while (i++ < min_idx)
			double_cmd("rr", a, b);
	}
	if (flg == 2)
	{
		temp = ft_lstsize(*b) - min_idx;
		while (i++ < temp)
			double_cmd("rrr", a, b);
	}
	ft_push("pa", b, a);
}

void	only_rotate(t_node **a, t_node **b, int min_idx, int flg)
{
	int	a_idx;
	int	i;

	i = 0;
	a_idx = get_aidx(*a, get_bn(*b, min_idx));
	if (a_idx >= ft_lstsize(*a))
		a_idx -= ft_lstsize(*a);
	if (flg == 3)
	{
		while (i++ < a_idx)
			double_cmd("rr", a, b);
		i = 0;
		while (i++ < (min_idx - a_idx))
			ft_rotate("rb", b);
	}
	if (flg == 4)
	{
		while (i++ < min_idx)
			double_cmd("rr", a, b);
		i = 0;
		while (i++ < (a_idx - min_idx))
			ft_rotate("ra", a);
	}
	ft_push("pa", b, a);
}

void	only_reverse(t_node **a, t_node **b, int min_idx, int flg)
{
	int	a_idx;
	int	i;

	i = 0;
	a_idx = ft_lstsize(*a) - get_aidx(*a, get_bn(*b, min_idx));
	min_idx = ft_lstsize(*b) - min_idx;
	if (flg == 5)
	{
		while (i++ < a_idx)
			double_cmd("rrr", a, b);
		i = 0;
		while (i++ < (min_idx - a_idx))
			ft_reverse_rotate("rrb", b);
	}
	if (flg == 6)
	{
		while (i++ < min_idx)
			double_cmd("rrr", a, b);
		i = 0;
		while (i++ < (a_idx - min_idx))
			ft_reverse_rotate("rra", a);
	}
	ft_push("pa", b, a);
}

void	mix_rotate(t_node **a, t_node **b, int min_idx, int flg)
{
	int	a_idx;

	a_idx = get_aidx(*a, get_bn(*b, min_idx));
	if (a_idx >= ft_lstsize(*a))
		a_idx -= ft_lstsize(*a);
	if (flg == 7)
	{
		min_idx = ft_lstsize(*b) - min_idx;
		while (a_idx--)
			ft_rotate("ra", a);
		while (min_idx--)
			ft_reverse_rotate("rrb", b);
	}
	if (flg == 8)
	{
		a_idx = ft_lstsize(*a) - a_idx;
		while (a_idx--)
			ft_reverse_rotate("rra", a);
		while (min_idx--)
			ft_rotate("rb", b);
	}
	ft_push("pa", b, a);
}

void	pa_flg(t_node **a, t_node **b, int min_idx, int flg)
{
	if (flg == 1 || flg == 2)
		all_double(a, b, min_idx, flg);
	if (flg == 3 || flg == 4)
		only_rotate(a, b, min_idx, flg);
	if (flg == 5 || flg == 6)
		only_reverse(a, b, min_idx, flg);
	if (flg == 7 || flg == 8)
		mix_rotate(a, b, min_idx, flg);
}
