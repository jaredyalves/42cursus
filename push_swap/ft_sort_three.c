/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:48:56 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:48:57 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stacks *stacks)
{
	int	max;

	max = ft_find_max(stacks->stack_a);
	if (stacks->size_a == 1)
		return ;
	else if (stacks->size_a == 2)
	{
		if (stacks->stack_a->number > stacks->stack_a->next->number)
			ft_sa(stacks, 1);
	}
	else if (stacks->size_a == 3)
	{
		if (stacks->stack_a->number == max)
			ft_ra(stacks, 1);
		if (stacks->stack_a->next->number == max)
			ft_rra(stacks, 1);
		if (stacks->stack_a->number > stacks->stack_a->next->number)
			ft_sa(stacks, 1);
	}
}
