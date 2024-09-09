/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_dupnsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:20:21 by sangseo           #+#    #+#             */
/*   Updated: 2024/08/12 13:20:26 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chk_dupnsort(t_node *a)
{
	int		flg;
	t_node	*b;

	flg = 1;
	b = (*a).next;
	if (b == NULL)
		return (1);
	while ((*a).next)
	{
		while (b)
		{
			if ((*a).n == (*b).n)
				return (-1);
			else if ((*a).n > (*b).n)
				flg = 0;
			b = (*b).next;
		}
		a = (*a).next;
		if (a)
			b = (*a).next;
	}
	return (flg);
}
