/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:13:42 by sangseo           #+#    #+#             */
/*   Updated: 2024/08/14 03:57:06 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(char *cmd, t_node **lst)
{
	t_node	*next;

	if (cmd)
		ft_printf("%s\n", cmd);
	if (!(*lst) || !((**lst).next))
		return ;
	next = (**lst).next;
	(**lst).next = (*next).next;
	(*next).next = *lst;
	*lst = next;
}

void	ft_push(char *cmd, t_node **give, t_node **take)
{
	t_node	*give_next;

	ft_printf("%s\n", cmd);
	if (!(*give))
		return ;
	give_next = (**give).next;
	(**give).next = *take;
	*take = *give;
	*give = give_next;
}

void	ft_rotate(char *cmd, t_node **lst)
{
	t_node	*first;
	t_node	*second;

	if (cmd)
		ft_printf("%s\n", cmd);
	if (!(*lst) || !((**lst).next))
		return ;
	first = *lst;
	second = (**lst).next;
	while ((**lst).next)
		*lst = (**lst).next;
	(**lst).next = first;
	(*first).next = NULL;
	*lst = second;
}

void	ft_reverse_rotate(char *cmd, t_node **lst)
{
	t_node	*first;
	t_node	*r_second;

	if (cmd)
		ft_printf("%s\n", cmd);
	if (!(*lst) || !((**lst).next))
		return ;
	first = *lst;
	while ((*((**lst).next)).next)
		*lst = (**lst).next;
	r_second = *lst;
	*lst = (**lst).next;
	(**lst).next = first;
	(*r_second).next = NULL;
}

void	double_cmd(char *cmd, t_node **a, t_node **b)
{
	if (ft_strncmp(cmd, "rrr", 3) == 0)
	{
		ft_reverse_rotate(cmd, a);
		ft_reverse_rotate(0, b);
	}
	else if (ft_strncmp(cmd, "ss", 2) == 0)
	{
		ft_swap(cmd, a);
		ft_swap(0, b);
	}
	else if (ft_strncmp(cmd, "rr", 2) == 0)
	{
		ft_rotate(cmd, a);
		ft_rotate(0, b);
	}
}
