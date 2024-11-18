/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_all_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:13:26 by sangseo           #+#    #+#             */
/*   Updated: 2024/11/18 13:45:10 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_aidx_reset(t_node **a, int bn, int *tmp, int *flg)
{
	if (*flg == 0)
	{
		if ((*a)->n < bn)
			*flg = -1;
		else
			*flg = 1;
	}
	*tmp = (*a)->n;
	(*a) = (*a)->next;
}

void	insert_minflg(int *min, int m_in, int *flg, int f_in)
{
	*min = m_in;
	*flg = f_in;
}
