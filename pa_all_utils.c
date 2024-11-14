/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_all_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:22:23 by sangseo           #+#    #+#             */
/*   Updated: 2024/11/15 03:56:12 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	cnt_a_inner(int a_size, int a_cnt, int b_cnt, int bn, int i)
// {
// 	int	r;
// 	int	min;

// 	if ((b_cnt != i && a_cnt > (a_size - a_cnt)) || \
// 		(b_cnt == i && a_cnt <= (a_size - a_cnt)))
// 	{
// 	}
// 	if (a_cnt > (a_size - a_cnt))
// 	{
// 		a_cnt = a_size - a_cnt;
// 		r = -1;
// 	}
// }

// int	cnt_a(t_node *a, int bn, int b_cnt, int i, int a_size)
// {
// 	int	a_cnt;
// 	int	flg;
// 	int	prev;
// 	int	min;

// 	flg = 0;
// 	a_cnt = 0;
// 	while (a)
// 	{
// 		if (flg == 0 && bn > a->n)
// 			flg = 1;
// 		else if ((flg == 1 && (bn < a->n || prev > a->n)) || \
// 				(flg == 0 && (prev > a->n && bn < a->n)))
// 			break ;
// 		a_cnt++;
// 		prev = a->n;
// 		a = a->next;
// 	}
// 	a_cnt = cnt_a_inner(a_size, a_cnt, b_cnt, bn, i);
// }

// int	get_paidx(t_node *a, t_node *b, int a_size, int b_size)
// {
// 	int	min;
// 	int	i;
// 	int	b_cnt;
// 	int	a_cnt;
// 	int	min_idx;

// 	i = 0;
// 	b_cnt = 0;
// 	while (b)
// 	{
// 		b_cnt = i;
// 		if (i > (b_size - i))
// 			b_cnt = b_size - i;
// 		a_cnt = cnt_a(a, b->n, b_cnt, i, a_size);
// 		i++;
// 		b = b->next;
// 	}
// }
int	get_aidx(t_node *a, int bn)
{
	int	tmp;
	int	idx;
	int	flg;

	flg = 0;
	if (a->n < bn)
		(flg = -1), (tmp = a->n), (idx = 1);
	if (a->n > bn)
		(flg = 1), (tmp = a->n), (idx = 1);
	a = a->next;
	while (a)
	{
		if (flg == 1)
		{
			if ((a->n) < tmp)
				(flg = -1), (tmp = a->n);
		}
		if (flg == -1)
		{
			if (!(((a->n) < bn) && (a->n >= tmp)))
				return (idx);
		}
		(tmp = a->n), (a = a->next), (idx++);
	}
	return (idx);
}

int	get_min_cnt(int	a_idx, int i, int a_size, int b_size)
{
	int	min;
	int	conv_a;
	int	conv_b;
	int	flg;

	flg = 0;
	if (a_idx >= a_size)
		a_idx -= a_size;
	conv_a = a_size - a_idx;
	conv_b = b_size - i;
	if (a_idx == i)
		(min = i), (flg = 1);
	if ((conv_a == conv_b) && (flg == 0 || ((flg == 1) && (conv_a < min))))
		(min = conv_a), (flg = 1);
	if (((a_idx - i) < 0) && (flg == 0 || ((flg == 1) && (i < min))))
		(min = i), (flg = 1);
	if (((a_idx - i) > 0) && (flg == 0 || ((flg == 1) && (a_idx < min))))
		(min = a_idx), (flg = 1);
	if (((conv_a - conv_b) < 0) && (conv_b < min))
		min = conv_b;
	if (((conv_a - conv_b) > 0) && (conv_a < min))
		min = conv_a;
	if ((a_idx + conv_b) < min)
		min = a_idx + conv_b;
	if ((conv_a + i) < min)
		min = conv_a + i;
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
			(min = tmp), (min_idx = i);
		i++;
		b = b->next;
	}
	return (min_idx);
}
