/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nums_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:48:20 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:48:21 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nums_to_list(t_stacks *stacks, t_nums *nums)
{
	int		i;
	t_stack	*list;

	i = 0;
	while (i < nums->size)
	{
		list = ft_list_new(nums->nums[i], -1);
		if (list == NULL)
			exit(EXIT_FAILURE);
		ft_list_add_back(&stacks->stack_a, list);
		stacks->size_a++;
		i++;
	}
	free(nums->nums);
}
