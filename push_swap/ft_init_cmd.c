/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:47:37 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/04 16:47:38 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_cmd(t_cmds *cmd)
{
	cmd->do_a = 0;
	cmd->do_b = 0;
	cmd->do_ab = 0;
	cmd->index = 0;
	cmd->step_a = 0;
	cmd->step_b = 0;
	cmd->cmd_total = 0;
	cmd->cmd_a = NULL;
	cmd->cmd_b = NULL;
}
