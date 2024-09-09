/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:51:38 by sangseo           #+#    #+#             */
/*   Updated: 2024/05/23 01:06:44 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_uspn(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n < 10)
	{
		i = n + '0';
		write(1, &i, 1);
	}
	else
	{
		ft_uspn(n / 10);
		ft_uspn(n % 10);
	}
}

int	ft_uspn_cnt(unsigned int n)
{
	int	i;

	i = 0;
	ft_uspn(n);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		i = ft_putnbr_base(nbr / 16, base);
		ft_putchar(base[nbr % 16]);
	}
	else
		ft_putchar(base[nbr % 16]);
	i++;
	return (i);
}

int	ft_puthex(const char *fmt, unsigned long long n)
{
	int	i;

	i = 0;
	if (*fmt == 'x')
		i = ft_putnbr_base((unsigned int)n, "0123456789abcdef");
	else if (*fmt == 'X')
		i = ft_putnbr_base((unsigned int)n, "0123456789ABCDEF");
	else
	{
		if (n == 0)
			return (write(1, "(nil)", 5));
		i += write(1, "0x", 2);
		i += ft_putnbr_base(n, "0123456789abcdef");
	}
	if (n == 0)
		return (1);
	return (i);
}
