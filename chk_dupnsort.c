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
	t_node	*temp;

	flg = 1;
	temp = (*a).next;
	if (temp == NULL)
		return (1);
	while ((*a).next)
	{
		while (temp)
		{
			if ((*a).n == (*temp).n)
				return (-1);
			else if ((*a).n > (*temp).n)
				flg = 0;
			temp = (*temp).next;
		}
		a = (*a).next;
		if (a)
			temp = (*a).next;
	}
	return (flg);
}
