/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:48:41 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:48:42 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stacks *stacks, int flag)
{
	t_stack	*tmp;

	if (stacks->size_a < 2)
		return ;
	tmp = stacks->stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = stacks->stack_a;
	stacks->stack_a = tmp->next;
	tmp->next = NULL;
	if (flag)
		write(STDOUT_FILENO, "rra\n", 4);
}

void	ft_rrb(t_stacks *stacks, int flag)
{
	t_stack	*tmp;

	if (stacks->size_b < 2)
		return ;
	tmp = stacks->stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = stacks->stack_b;
	stacks->stack_b = tmp->next;
	tmp->next = NULL;
	if (flag)
		write(STDOUT_FILENO, "rrb\n", 4);
}

void	ft_rrr(t_stacks *stacks, int flag)
{
	ft_rra(stacks, 0);
	ft_rrb(stacks, 0);
	if (flag)
		write(STDOUT_FILENO, "rrr\n", 4);
}
