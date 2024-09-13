/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:33:39 by sangseo           #+#    #+#             */
/*   Updated: 2024/08/14 03:24:16 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_node *a)
{
	t_node	*temp;

	while (a)
	{
		temp = (*a).next;
		free(a);
		a = temp;
	}
	ft_printf("Error\n");
	exit(1);
}

int	chk_ascending(t_node *lst)
{
	int	max;
	int	min;
	int	flg;

	flg = 1;
	max = (*lst).n;
	min = max;
	lst = (*lst).next;
	while (lst)
	{
		if (max > (*lst).n)
		{
			if (flg == 1)
				flg = 0;
			else
				return (0);
		}
		if (flg == 0 && ((*lst).n > min))
			return (0);
		max = (*lst).n;
		lst = (*lst).next;
	}
	return (1);
}
/*
int	find_min_node(t_node *lst)
{
	int	min;
	int	i;
	int	min_idx;

	i = 0;
	min_idx = 0;
	min = (*lst).n;
	lst = (*lst).next;
	while (lst)
	{
		i++;
		if (min > (*lst).n)
		{
			min = (*lst).n;
			min_idx = i;
		}
		lst = (*lst).next;
	}
	return (min_idx);
}

void	min_to_top(t_node **lst, int size, int *max_idx, int *max_top)
{
	int	min_idx;

	min_idx = find_min_node(*lst);
	if (min_idx <= (size / 2))
	{
		while (min_idx--)
		{
			ft_rotate("ra", lst);
			(*max_idx)--;
			(*max_top)--;
		}
	}
	else
	{
		while (size - min_idx++)
		{
			ft_reverse_rotate("rra", lst);
			(*max_idx)++;
			(*max_top)++;
		}
	}
}
*/
int	find_min_node(t_node *lst)
{
	int	min;
	int	i;
	int	min_idx;

	i = 0;
	min_idx = 0;
	min = (*lst).n;
	lst = (*lst).next;
	while (lst)
	{
		i++;
		if (min > (*lst).n)
		{
			min = (*lst).n;
			min_idx = i;
		}
		lst = (*lst).next;
	}
	return (min_idx);
}

void	min_to_top(t_node **lst, int size)
{
	int	min_idx;

	min_idx = find_min_node(*lst);
	if (min_idx <= (size / 2))
	{
		while (min_idx--)
			ft_rotate("ra", lst);
	}
	else
	{
		while (size - min_idx++)
			ft_reverse_rotate("rra", lst);
	}
}
/*
int	find_max_node(t_node *lst)
{
	int	this_idx;
	int	max;
	int	max_idx;

	this_idx = 0;
	max_idx = 0;
	max = (*lst).n;
	while (lst)
	{
		if (max < (*lst).n)
		{
			max = (*lst).n;
			max_idx = this_idx;
		}
		lst = (*lst).next;
		this_idx++;
	}
	return (max_idx);
}
*/