/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_min_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:47:01 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:47:02 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec_min_cmds(t_stacks *stacks, t_cmds *cmd)
{
	while (cmd->do_a)
	{
		if (!ft_strncmp(cmd->cmd_a[cmd->index], "ra", 10))
			ft_ra(stacks, 1);
		else if (!ft_strncmp(cmd->cmd_a[cmd->index], "rra", 10))
			ft_rra(stacks, 1);
		cmd->do_a--;
	}
	while (cmd->do_b)
	{
		if (!ft_strncmp(cmd->cmd_b[cmd->index], "rb", 10))
			ft_rb(stacks, 1);
		else if (!ft_strncmp(cmd->cmd_b[cmd->index], "rrb", 10))
			ft_rrb(stacks, 1);
		cmd->do_b--;
	}
	while (cmd->do_ab)
	{
		if (!ft_strncmp(cmd->cmd_a[cmd->index], "ra", 10))
			ft_rr(stacks, 1);
		else if (!ft_strncmp(cmd->cmd_a[cmd->index], "rra", 10))
			ft_rrr(stacks, 1);
		cmd->do_ab--;
	}
}
