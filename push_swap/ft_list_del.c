/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:48:01 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:48:02 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_del(t_stacks *stacks)
{
	int		i;
	t_stack	*curr;
	t_stack	*temp;

	i = 0;
	curr = stacks->stack_a;
	while (i < stacks->size_a)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
		i++;
	}
	i = 0;
	curr = stacks->stack_b;
	while (i < stacks->size_b)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
		i++;
	}
}
