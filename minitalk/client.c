/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:41:36 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/06 15:55:44 by jcapistr         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
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
		ft_putstr_fd("The string is not valid or has more than 1000 chars.\n",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd("[CLIENT]: Sending the string to the server...\n",
		STDOUT_FILENO);
	ft_send_string(ft_atoi(argv[1]), argv[2]);
	ft_putstr_fd("[CLIENT]: The string was sent to the server.\n",
		STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
