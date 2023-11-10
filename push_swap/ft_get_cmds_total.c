/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmds_total.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:47:28 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:54:32 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_cmds_total(t_stacks *stacks, t_cmds *cmd)
{
	int	i;

	i = 1;
	cmd->cmd_total[0] = cmd->step_a[0];
	while (i < stacks->size_b)
	{
		if ((!ft_strncmp(cmd->cmd_a[i], "ra", 10)
				&& !ft_strncmp(cmd->cmd_b[i], "rb", 10))
			|| (!ft_strncmp(cmd->cmd_a[i], "rra", 10)
				&& !ft_strncmp(cmd->cmd_b[i], "rrb", 10)))
		{
			if (cmd->step_a[i] > cmd->step_b[i])
				cmd->cmd_total[i] = cmd->step_a[i];
			else
				cmd->cmd_total[i] = cmd->step_b[i];
		}
		else if ((!ft_strncmp(cmd->cmd_a[i], "ra", 10)
				&& !ft_strncmp(cmd->cmd_b[i], "rrb", 10))
			|| (!ft_strncmp(cmd->cmd_a[i], "rra", 10)
				&& !ft_strncmp(cmd->cmd_b[i], "rb", 10)))
			cmd->cmd_total[i] = cmd->step_a[i] + cmd->step_b[i];
		else if (cmd->cmd_a[i] == NULL)
			cmd->cmd_total[i] = cmd->step_b[i];
		i++;
	}
}
