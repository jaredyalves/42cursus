/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:05:25 by jcapistr          #+#    #+#             */
/*   Updated: 2023/01/15 13:13:20 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(long long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_print_chr('-');
		nbr = -nbr;
	}
	if (nbr < 10)
		count += ft_print_chr((char)(nbr + '0'));
	else
	{
		count += ft_print_nbr(nbr / 10);
		count += ft_print_chr((char)((nbr % 10) + '0'));
	}
	return (count);
}
