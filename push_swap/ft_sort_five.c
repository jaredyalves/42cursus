/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:48:46 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:48:47 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five(t_stacks *stacks)
{
	int	i;
	int	min;
	int	max;

	i = stacks->size_b;
	min = ft_find_min(stacks->stack_a);
	max = ft_find_max(stacks->stack_a);
	while (stacks->size_b - i != 2)
	{
		if (stacks->stack_a->number == min || stacks->stack_a->number == max)
			ft_pb(stacks, 1);
		else
			ft_ra(stacks, 1);
	}
	ft_sort_three(stacks);
	ft_pa(stacks, 1);
	ft_pa(stacks, 1);
	if (stacks->stack_a->number == max)
		ft_ra(stacks, 1);
	else
	{
		ft_sa(stacks, 1);
		ft_ra(stacks, 1);
	}
}
