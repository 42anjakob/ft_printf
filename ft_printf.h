/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:13:07 by anjakob           #+#    #+#             */
/*   Updated: 2025/10/31 20:25:36 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	put_char(const char s, int *len);
int	put_str(const char *s, int *len);
int	put_nbr(const long n, int *len);
int	print_base(const char *s, const unsigned long n, int *len);
int	print_mem(const unsigned long n, int *len);

#endif