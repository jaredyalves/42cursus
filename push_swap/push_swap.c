/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:49:04 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:49:05 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_nums		nums;
	t_cmds		cmd;
	t_stacks	stacks;

	if (argc == 1)
		exit(EXIT_FAILURE);
	ft_init_nums(&nums);
	ft_init_cmd(&cmd);
	ft_init_stacks(&stacks);
	ft_parse(argc, argv, &nums);
	ft_check_duplicates(&nums);
	if (!ft_nums_is_sorted(&nums))
	{
		ft_nums_to_list(&stacks, &nums);
		if (stacks.size_a <= 3)
			ft_sort_three(&stacks);
		else if (stacks.size_a <= 5)
			ft_sort_five(&stacks);
		else
			ft_sort_more(&stacks, &cmd);
	}
	else
		ft_free_nums(nums.nums);
	ft_list_del(&stacks);
	return (0);
}
