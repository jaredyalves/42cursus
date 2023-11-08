/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:21:59 by jcapistr          #+#    #+#             */
/*   Updated: 2023/01/15 13:46:27 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long nbr, ...)
{
	char	*base;
	int		count;
	int		mode;
	va_list	args;

	count = 0;
	va_start(args, nbr);
	mode = va_arg(args, int);
	if (mode == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	va_end(args);
	if (nbr < 16)
		count += ft_print_chr(base[nbr]);
	else
	{
		count += ft_print_hex(nbr / 16, mode);
		count += ft_print_chr(base[nbr % 16]);
	}
	return (count);
}
