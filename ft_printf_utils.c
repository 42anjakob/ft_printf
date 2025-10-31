/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:12:56 by anjakob           #+#    #+#             */
/*   Updated: 2025/10/31 20:11:19 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(const char c, int *len)
{
	if (write(1, &c, 1) == -1)
		return (0);
	*len += 1;
	return (1);
}

int	put_str(const char *s, int *len)
{
	if (!s)
		return (put_str("(null)", len));
	while (*s)
	{
		if (!put_char(*s, len))
			return (0);
		s++;
	}
	return (1);
}

int	put_nbr(const long n, int *len)
{
	char	c;

	if (n < 0)
	{
		if (!put_char('-', len))
			return (0);
		put_nbr(-n, len);
	}
	else if (n < 10)
	{
		c = n + '0';
		if (!put_char(c, len))
			return (0);
	}
	else
	{
		put_nbr(n / 10, len);
		c = n % 10 + '0';
		if (!put_char(c, len))
			return (0);
	}
	return (1);
}

int	print_base(const char *s, const unsigned long n, int *len)
{
	char			c;
	unsigned int	base;

	base = 0;
	while (s[base])
		base++;
	if (n < base)
	{
		c = s[n];
		if (!put_char(c, len))
			return (0);
	}
	else
	{
		if (!print_base(s, n / base, len))
			return (0);
		c = s[n % base];
		if (!put_char(c, len))
			return (0);
	}
	return (1);
}

int	print_mem(const unsigned long n, int *len)
{
	if (n == 0)
	{
		if (!put_str("(nil)", len))
			return (0);
	}
	else if (!put_str("0x", len) || !print_base("0123456789abcdef", n, len))
		return (0);
	return (1);
}
