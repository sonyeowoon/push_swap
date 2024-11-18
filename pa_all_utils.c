/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_all_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:22:23 by sangseo           #+#    #+#             */
/*   Updated: 2024/11/18 14:12:32 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_aidx(t_node *a, int bn)
{
	int	tmp;
	int	idx;
	int	flg;

	flg = 0;
	idx = 0;
	while (a)
	{
		if (flg == 1)
		{
			if ((a->n) < tmp)
			{
				flg = -1;
				tmp = a->n;
			}
		}
		if (flg == -1)
		{
			if (!(((a->n) < bn) && (a->n >= tmp)))
				return (idx);
		}
		get_aidx_reset(&a, bn, &tmp, &flg);
		idx++;
	}
	return (idx);
}

int	get_min_cnt(int a_idx, int i, int a_size, int b_size)
{
	int	min;
	int	flg;

	flg = 0;
	if (a_idx >= a_size)
		a_idx -= a_size;
	if (a_idx == i)
		insert_minflg(&min, i, &flg, 1);
	if (((a_size - a_idx) == (b_size - i)) && (flg == 0 || \
		((flg == 1) && ((a_size - a_idx) < min))))
		insert_minflg(&min, (a_size - a_idx), &flg, 1);
	if (((a_idx - i) < 0) && (flg == 0 || ((flg == 1) && (i < min))))
		insert_minflg(&min, i, &flg, 1);
	if (((a_idx - i) > 0) && (flg == 0 || ((flg == 1) && (a_idx < min))))
		insert_minflg(&min, a_idx, &flg, 1);
	if ((((a_size - a_idx) - (b_size - i)) < 0) && ((b_size - i) < min))
		min = (b_size - i);
	if ((((a_size - a_idx) - (b_size - i)) > 0) && ((a_size - a_idx) < min))
		min = (a_size - a_idx);
	if ((a_idx + (b_size - i)) < min)
		min = a_idx + (b_size - i);
	if (((a_size - a_idx) + i) < min)
		min = (a_size - a_idx) + i;
	return (min);
}

int	get_paidx(t_node *a, t_node *b, int a_size, int b_size)
{
	int	min;
	int	i;
	int	min_idx;
	int	a_idx;
	int	tmp;

	i = 0;
	min_idx = 0;
	while (b)
	{
		a_idx = get_aidx(a, b->n);
		tmp = get_min_cnt(a_idx, i, a_size, b_size);
		if (i == 0)
			min = tmp;
		if (tmp < min)
		{
			min = tmp;
			min_idx = i;
		}
		i++;
		b = b->next;
	}
	return (min_idx);
}

int	get_min_flg(int a_idx, int i, int a_size, int b_size)
{
	int	min;
	int	flg;

	flg = 0;
	if (a_idx >= a_size)
		a_idx -= a_size;
	if (a_idx == i)
		insert_minflg(&min, i, &flg, 1);
	if (((a_size - a_idx) == (b_size - i)) && (flg == 0 || \
		((flg == 1) && ((a_size - a_idx) < min))))
		insert_minflg(&min, (a_size - a_idx), &flg, 2);
	if (((a_idx - i) < 0) && (flg == 0 || ((flg >= 1) && (i < min))))
		insert_minflg(&min, i, &flg, 3);
	if (((a_idx - i) > 0) && (flg == 0 || ((flg >= 1) && (a_idx < min))))
		insert_minflg(&min, a_idx, &flg, 4);
	if ((((a_size - a_idx) - (b_size - i)) < 0) && ((b_size - i) < min))
		insert_minflg(&min, (b_size - i), &flg, 5);
	if ((((a_size - a_idx) - (b_size - i)) > 0) && ((a_size - a_idx) < min))
		insert_minflg(&min, (a_size - a_idx), &flg, 6);
	if ((a_idx + (b_size - i)) < min)
		insert_minflg(&min, (a_idx + (b_size - i)), &flg, 7);
	if (((a_size - a_idx) + i) < min)
		insert_minflg(&min, ((a_size - a_idx) + i), &flg, 8);
	return (flg);
}

void	pa_min(t_node **a, t_node **b, int min_idx)
{
	t_node	*temp;
	int		i;
	int		a_idx;
	int		flg;

	temp = *b;
	i = 0;
	while (i++ < min_idx)
		temp = temp->next;
	a_idx = get_aidx(*a, temp->n);
	flg = get_min_flg(a_idx, min_idx, ft_lstsize(*a), ft_lstsize(*b));
	pa_flg(a, b, min_idx, flg);
}
