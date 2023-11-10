/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:41:44 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/06 15:51:08 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig)
{
	static int	idx = 0;
	static int	cnt = 0;
	static char	chr = 0;
	static char	str[1000] = {0};

	chr |= (sig == SIGUSR2);
	if (++cnt == 8)
	{
		str[idx++] = chr;
		if (chr == '\0')
		{
			ft_putstr_fd("[CLIENT]: ", STDOUT_FILENO);
			ft_putstr_fd(str, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
			idx = 0;
		}
		cnt = 0;
		chr = 0;
	}
	else
		chr <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("[SERVER]: PID is ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
