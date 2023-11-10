/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:47:24 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:47:25 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_greater_than_max(t_stacks *stacks, t_cmds *cmd, int max, int i)
{
	int	idx;

	idx = ft_find_idx(stacks->stack_a, max);
	if (idx < stacks->size_a / 2)
	{
		cmd->step_a[i] = idx + 1;
		cmd->cmd_a[i] = "ra";
	}
	else
	{
		cmd->step_a[i] = stacks->size_a - idx - 1;
		cmd->cmd_a[i] = "rra";
	}
}

static void	ft_lower_than_min(t_stacks *stacks, t_cmds *cmd, int min, int i)
{
	int	idx;

	idx = ft_find_idx(stacks->stack_a, min);
	if (idx <= stacks->size_a / 2)
	{
		cmd->step_a[i] = idx;
		cmd->cmd_a[i] = "ra";
	}
	else
	{
		cmd->step_a[i] = stacks->size_a - idx;
		cmd->cmd_a[i] = "rra";
	}
}

static void	ft_between_min_max(t_stacks *stacks, t_cmds *cmd, int i,
		t_stack *tmp_b)
{
	int		j;
	t_stack	*tmp;

	j = 0;
	tmp = stacks->stack_a;
	while (j < stacks->size_a - 1)
	{
		if (tmp_b->number > tmp->number && tmp_b->number < tmp->next->number)
		{
			if (j < stacks->size_a / 2)
			{
				cmd->step_a[i] = j + 1;
				cmd->cmd_a[i] = "ra";
			}
			else
			{
				cmd->step_a[i] = stacks->size_a - (j + 1);
				cmd->cmd_a[i] = "rra";
			}
			j = stacks->size_a;
		}
		tmp = tmp->next;
		j++;
	}
}

void	ft_get_cmds_a(t_stacks *stacks, t_cmds *cmd)
{
	int		i;
	int		min;
	int		max;
	t_stack	*tmp_b;

	tmp_b = stacks->stack_b;
	i = 0;
	while (i < stacks->size_b)
	{
		min = ft_find_min(stacks->stack_a);
		max = ft_find_max(stacks->stack_a);
		if (tmp_b->number > max)
			ft_greater_than_max(stacks, cmd, max, i);
		else if (tmp_b->number < min)
			ft_lower_than_min(stacks, cmd, min, i);
		else
			ft_between_min_max(stacks, cmd, i, tmp_b);
		if (cmd->step_a[i] == 0)
			cmd->cmd_a[i] = NULL;
		tmp_b = tmp_b->next;
		i++;
	}
}

void	ft_get_cmds_b(t_stacks *stacks, t_cmds *cmd)
{
	int	i;

	i = 1;
	while (i < stacks->size_b)
	{
		if (i <= stacks->size_b / 2)
		{
			cmd->step_b[i] = i;
			cmd->cmd_b[i] = "rb";
		}
		else
		{
			cmd->step_b[i] = stacks->size_b - i;
			cmd->cmd_b[i] = "rrb";
		}
		i++;
	}
	if (stacks->size_b % 2 == 0)
		if (!ft_strncmp(cmd->cmd_a[stacks->size_b / 2], "rra", 10))
			cmd->cmd_b[stacks->size_b / 2] = "rrb";
}
