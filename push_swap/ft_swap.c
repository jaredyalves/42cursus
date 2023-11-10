/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:48:59 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:49:00 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stacks *stacks, int flag)
{
	t_stack	*tmp;

	if (stacks->size_a < 2)
		return ;
	tmp = stacks->stack_a->next;
	stacks->stack_a->next = stacks->stack_a->next->next;
	tmp->next = stacks->stack_a;
	stacks->stack_a = tmp;
	if (flag)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	ft_sb(t_stacks *stacks, int flag)
{
	t_stack	*tmp;

	if (stacks->size_b < 2)
		return ;
	tmp = stacks->stack_b->next;
	stacks->stack_b->next = stacks->stack_b->next->next;
	tmp->next = stacks->stack_b;
	stacks->stack_b = tmp;
	if (flag)
		write(STDOUT_FILENO, "sb\n", 3);
}

void	ft_ss(t_stacks *stacks, int flag)
{
	ft_sa(stacks, 0);
	ft_sb(stacks, 0);
	if (flag)
		write(STDOUT_FILENO, "ss\n", 3);
}
