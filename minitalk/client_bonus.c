/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:41:36 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/06 16:00:28 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_pid_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_string_is_valid(char *str)
{
	if (str == NULL || ft_strlen(str) == 0 || ft_strlen(str) > 1000)
		return (0);
	return (1);
}

static void	ft_send_string(int server_pid, char *string)
{
	int		cnt;
	char	chr;

	ft_putstr_fd("[CLIENT]: Sending the string to the server...\n",
		STDOUT_FILENO);
	while (*string != '\0')
	{
		cnt = 8;
		chr = *string++;
		while (cnt--)
		{
			if (chr >> cnt & 1)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			usleep(250);
		}
	}
	cnt = 8;
	while (cnt--)
	{
		kill(server_pid, SIGUSR1);
		usleep(250);
	}
}

static void	handler(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_putstr_fd("[SERVER]: The string was received.\n", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_putstr_fd("./client [Server PID] [String to send]\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!ft_pid_is_valid(argv[1]))
	{
		ft_putstr_fd("The server PID is not valid.\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!ft_string_is_valid(argv[2]))
	{
		ft_putstr_fd("The string is not valid.\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR2, &sa, NULL);
	ft_send_string(ft_atoi(argv[1]), argv[2]);
	ft_putstr_fd("[CLIENT]: The string was sent.\n", STDOUT_FILENO);
	while (1)
		pause();
}
