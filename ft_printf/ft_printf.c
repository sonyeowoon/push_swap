/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:50:12 by sangseo           #+#    #+#             */
/*   Updated: 2024/05/26 01:01:03 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_arg(const char *fmt, va_list ap)
{
	int	i;

	i = -1;
	if (*fmt == '%')
		i = ft_putchar('%');
	else if (*fmt == 'd' || *fmt == 'i')
		i = ft_putnbr_cnt(va_arg(ap, int));
	else if (*fmt == 'u')
		i = ft_uspn_cnt(va_arg(ap, unsigned int));
	else if (*fmt == 'c')
		i = ft_putchar(va_arg(ap, int));
	else if (*fmt == 's')
		i = ft_putstr(va_arg(ap, char *));
	else if (*fmt == 'x' || *fmt == 'X')
		i = ft_puthex(fmt, va_arg(ap, unsigned int));
	else if (*fmt == 'p')
		i = ft_puthex(fmt, va_arg(ap, unsigned long long));
	return (i);
}

static int	check_format(const char *format, va_list ap)
{
	int		cnt;
	int		err;

	err = 0;
	cnt = 0;
	while (format)
	{
		if (!(*format))
			break ;
		if (*format == '%')
		{
			err = print_arg(++format, ap);
			if (err == -1)
				return (-1);
			cnt += err;
		}
		else
		{
			ft_putchar(*format);
			cnt++;
		}
		format++;
	}
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;

	if (write(1, "", 0) == -1)
		return (-1);
	if (!format)
		return (-1);
	va_start(ap, format);
	result = check_format(format, ap);
	va_end(ap);
	return (result);
}
