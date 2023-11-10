/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_idx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:47:05 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:47:06 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_idx(t_stack *stack, int number)
{
	int		idx;
	t_stack	*tmp;

	idx = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->number == number)
			return (idx);
		idx++;
		tmp = tmp->next;
	}
	return (idx);
}
