/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:16:37 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/12 09:14:05 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	c_flag;

void	c_sig_handler(int signum)
{
	ft_printf("communication established\n");
}

void	send_pid(pid_t client, pid_t server)
{
	int	i;

	i = 1;
	while (i < 33)
	{
		if (client & (1 << i))
			kill(server, SIGUSR1);
		else
			kill(server, SIGUSR2);
		usleep(200);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t				server;
	pid_t				client;
	struct sigaction	c_action;

	if (argc == 1)
		graceful_exit("No pid provided to client. Try again!\n");
	server = atoi(argv[1]);
	client = getpid();
	ft_printf("client pid: %d\n", client);
	init_sigaction(&c_action, c_sig_handler);
	send_pid(client, server);
	pause();
	pause();
	pause();
	pause();
}
