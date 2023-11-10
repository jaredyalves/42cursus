/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:43:51 by jcapistr          #+#    #+#             */
/*   Updated: 2023/01/15 11:51:34 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		i += ft_print_str("(null)");
	while (str != NULL && str[i] != '\0')
		i += ft_print_chr(str[i]);
	return (i);
}
