/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:48:30 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:48:31 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stacks *stacks, int flag)
{
	t_stack	*tmp;
	t_stack	*new;

	if (!stacks->size_b)
		return ;
	tmp = stacks->stack_b;
	stacks->size_a++;
	new = ft_list_new(stacks->stack_b->number, stacks->stack_b->index);
	if (new == NULL)
		exit(EXIT_FAILURE);
	ft_list_add_front(&stacks->stack_a, new);
	stacks->stack_b = stacks->stack_b->next;
	free(tmp);
	stacks->size_b--;
	if (flag)
		write(STDOUT_FILENO, "pa\n", 3);
}

void	ft_pb(t_stacks *stacks, int flag)
{
	t_stack	*tmp;
	t_stack	*new;

	if (!stacks->size_a)
		return ;
	tmp = stacks->stack_a;
	stacks->size_b++;
	new = ft_list_new(stacks->stack_a->number, stacks->stack_a->index);
	if (new == NULL)
		exit(EXIT_FAILURE);
	ft_list_add_front(&stacks->stack_b, new);
	stacks->stack_a = stacks->stack_a->next;
	free(tmp);
	stacks->size_a--;
	if (flag)
		write(STDOUT_FILENO, "pb\n", 3);
}
