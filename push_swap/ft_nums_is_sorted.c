/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nums_is_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:48:16 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:48:17 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nums_is_sorted(t_nums *nums)
{
	int	i;

	i = 0;
	while (i < nums->size - 1)
	{
		if (nums->nums[i] > nums->nums[i + 1])
			return (0);
		i++;
	}
	return (1);
}
