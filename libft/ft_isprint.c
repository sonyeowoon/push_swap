/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:21:17 by sangseo           #+#    #+#             */
/*   Updated: 2024/03/25 23:46:06 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int n)
{
	if (n >= 32 && n <= 126)
		return (16384);
	else
		return (0);
}
