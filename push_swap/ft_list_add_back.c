/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:47:53 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:47:53 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = *stack;
	if (last)
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*stack = new;
}
