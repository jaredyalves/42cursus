/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:48:36 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:48:37 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks *stacks, int flag)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (stacks->size_a < 2)
		return ;
	tmp_1 = stacks->stack_a;
	while (tmp_1->next)
		tmp_1 = tmp_1->next;
	tmp_2 = stacks->stack_a->next;
	stacks->stack_a->next = NULL;
	tmp_1->next = stacks->stack_a;
	stacks->stack_a = tmp_2;
	if (flag)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	ft_rb(t_stacks *stacks, int flag)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (stacks->size_b < 2)
		return ;
	tmp_1 = stacks->stack_b;
	while (tmp_1->next)
		tmp_1 = tmp_1->next;
	tmp_2 = stacks->stack_b->next;
	stacks->stack_b->next = NULL;
	tmp_1->next = stacks->stack_b;
	stacks->stack_b = tmp_2;
	if (flag)
		write(STDOUT_FILENO, "rb\n", 3);
}

void	ft_rr(t_stacks *stacks, int flag)
{
	ft_ra(stacks, 0);
	ft_rb(stacks, 0);
	if (flag)
		write(STDOUT_FILENO, "rr\n", 3);
}
