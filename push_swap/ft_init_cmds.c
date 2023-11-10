/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:47:41 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:47:42 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_cmds(t_stacks *stacks, t_cmds *cmd)
{
	cmd->do_a = 0;
	cmd->do_b = 0;
	cmd->do_ab = 0;
	cmd->index = 0;
	cmd->step_a = (int *)ft_calloc(sizeof(int), stacks->size_b);
	cmd->step_b = (int *)ft_calloc(sizeof(int), stacks->size_b);
	cmd->cmd_a = (char **)ft_calloc(sizeof(char *), stacks->size_b);
	cmd->cmd_b = (char **)ft_calloc(sizeof(char *), stacks->size_b);
	cmd->cmd_total = (int *)ft_calloc(sizeof(int), stacks->size_b);
	if (!(cmd->step_a && cmd->step_b && cmd->cmd_a && cmd->cmd_b
			&& cmd->cmd_total))
		exit(EXIT_FAILURE);
}
