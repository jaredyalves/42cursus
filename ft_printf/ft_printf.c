/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:58:58 by jcapistr          #+#    #+#             */
/*   Updated: 2023/01/15 13:28:02 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(va_list args, char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_print_chr(va_arg(args, int));
	else if (format == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		count += ft_print_addr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		count += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_print_nbr(va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		count += ft_print_chr('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_print_format(args, str[++i]);
		else
			count += ft_print_chr(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
