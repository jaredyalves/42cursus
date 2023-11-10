/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:47:32 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:47:33 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_min_cmds(t_cmds *cmd)
{
	if ((!ft_strncmp(cmd->cmd_a[cmd->index], "ra", 10)
			&& !ft_strncmp(cmd->cmd_b[cmd->index], "rb", 10))
		|| (!ft_strncmp(cmd->cmd_a[cmd->index], "rra", 10)
			&& !ft_strncmp(cmd->cmd_b[cmd->index], "rrb", 10)))
	{
		if (cmd->step_a[cmd->index] > cmd->step_b[cmd->index])
		{
			cmd->do_a = cmd->step_a[cmd->index] - cmd->step_b[cmd->index];
			cmd->do_ab = cmd->step_b[cmd->index];
		}
		else
		{
			cmd->do_b = cmd->step_b[cmd->index] - cmd->step_a[cmd->index];
			cmd->do_ab = cmd->step_a[cmd->index];
		}
	}
	else
	{
		cmd->do_a = cmd->step_a[cmd->index];
		cmd->do_b = cmd->step_b[cmd->index];
	}
}
