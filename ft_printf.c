/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:12:54 by anjakob           #+#    #+#             */
/*   Updated: 2025/10/31 20:28:26 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(const char c, va_list arg, int *len)
{
	if (!c)
		return (0);
	else if (c == 'c' && !put_char(va_arg(arg, int), len))
		return (0);
	else if (c == 's' && !put_str(va_arg(arg, char *), len))
		return (0);
	else if (c == 'p' && !print_mem(va_arg(arg, unsigned long), len))
		return (0);
	else if ((c == 'd' || c == 'i') && !put_nbr(va_arg(arg, int), len))
		return (0);
	else if (c == 'u'
		&& !print_base("0123456789", va_arg(arg, unsigned int), len))
		return (0);
	else if (c == 'x'
		&& !print_base("0123456789abcdef", va_arg(arg, unsigned int), len))
		return (0);
	else if (c == 'X'
		&& !print_base("0123456789ABCDEF", va_arg(arg, unsigned int), len))
		return (0);
	else if (c == '%' && !put_char('%', len))
		return (0);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!print_arg(*format, arg, &len))
				return (-1);
		}
		else
		{
			if (!put_char(*format, &len))
				return (-1);
		}
		format++;
	}
	va_end(arg);
	return (len);
}
