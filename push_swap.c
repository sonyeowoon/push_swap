/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:07:16 by sangseo           #+#    #+#             */
/*   Updated: 2024/11/18 16:48:58 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chk_arg(char **av)
{
	int	i;
	int	flg;

	flg = 0;
	while (*(++av))
	{
		i = -1;
		while ((*av)[++i])
		{
			if (flg != 1 && ft_isspace((*av)[i]))
				flg = 0;
			else if (flg > 0 && !(ft_isdigit((*av)[i])))
				return (0);
			else if ((*av)[i] == '+' || (*av)[i] == '-')
				flg = 1;
			else if (ft_isdigit((*av)[i]))
				flg = 2;
			else
				return (0);
		}
		if (flg == 1)
			return (0);
		flg = 0;
	}
	return (1);
}

void	push_swap(t_node *a)
{
	int		d;
	t_node	*b;

	b = 0;
	d = chk_dupnsort(a);
	if (d == -1)
		ft_error(a);
	if (d == 1)
		stack_free(a);
	if (d == 0)
	{
		if (chk_ascending(a))
		{
			min_to_top(&a, ft_lstsize(a));
			stack_free(a);
		}
		else
			ft_sorting(a, b);
	}
}

int	main(int ac, char **av)
{
	t_node	*a;

	a = 0;
	if (ac < 2)
		return (0);
	if (chk_arg(av) == 0)
		ft_error(a);
	a = make_stack(av);
	if (a == 0)
		ft_error(a);
	push_swap(a);
	return (0);
}
