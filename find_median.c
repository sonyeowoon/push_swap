/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:54:34 by sangseo           #+#    #+#             */
/*   Updated: 2024/11/18 19:53:03 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_node *lst)
{
	int	min;

	min = (*lst).n;
	while (lst)
	{
		if (min > (*lst).n)
			min = (*lst).n;
		lst = (*lst).next;
	}
	return (min);
}

int	get_max(t_node *lst)
{
	int	max;

	max = (*lst).n;
	while (lst)
	{
		if (max < (*lst).n)
			max = (*lst).n;
		lst = (*lst).next;
	}
	return (max);
}

static int	calc_diff(t_node *lst, int median, int min, int max)
{
	int	left;
	int	right;

	left = 0;
	right = 0;
	while (lst)
	{
		if ((*lst).n >= min && (*lst).n <= median)
			left++;
		else if ((*lst).n > median && (*lst).n <= max)
			right++;
		lst = (*lst).next;
	}
	if ((right - left) >= -1 && (right - left) <= 1)
		return (0);
	else if ((min < 0 && max < 0) && (left == 2 && right == 0))
		return (0);
	else if ((max - min) <= 1)
		return (0);
	else if ((right - left) < -1)
		return (-1);
	else
		return (1);
}

int	find_median(t_node *lst, int flg, int min, int max)
{
	int	median;

	if (flg == 0)
	{
		min = get_min(lst);
		max = get_max(lst);
	}
	median = (int)(((long)min + (long)max) / 2);
	flg = calc_diff(lst, median, min, max);
	if (flg == 0)
		return (median);
	else if (flg < 0)
		median = find_median(lst, flg, min, median);
	else
		median = find_median(lst, flg, median, max);
	return (median);
}
