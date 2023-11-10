/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:41:44 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/06 15:51:30 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	idx = 0;
	static int	cnt = 0;
	static char	chr = 0;
	static char	str[1000] = {0};
	int			client_pid;

	(void)ucontext;
	client_pid = info->si_pid;
	chr |= (sig == SIGUSR2);
	if (++cnt == 8)
	{
		str[idx++] = chr;
		if (chr == '\0')
		{
			ft_putstr_fd("[CLIENT]: ", STDOUT_FILENO);
			ft_putstr_fd(str, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
			kill(client_pid, SIGUSR2);
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
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
