/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:59:03 by jcapistr          #+#    #+#             */
/*   Updated: 2023/01/15 13:26:21 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_print_addr(unsigned long long addr);
int	ft_print_chr(char chr);
int	ft_print_hex(unsigned long long nbr, ...);
int	ft_print_nbr(long long nbr);
int	ft_print_str(const char *str);
int	ft_printf(const char *str, ...);

#endif
