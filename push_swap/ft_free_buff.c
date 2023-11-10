/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:55:45 by jcapistr          #+#    #+#             */
/*   Updated: 2023/07/01 16:55:46 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_buff(char **buff)
{
	int	i;

	if (buff == NULL)
		return ;
	i = 0;
	while (buff[i] != NULL)
	{
		free(buff[i]);
		buff[i] = NULL;
		i++;
	}
	free(buff);
}
