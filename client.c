/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:16:37 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/15 17:40:50 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

bool	g_flag;

static void	c_sig_handler(int signum)
{
	if (signum == SIGUSR1)
		g_flag = true;
}

static int	get_server(int argc, char *argv[])
{
	int	server;

	if (argc == 1)
	{
		ft_printf("No pid provided to client. Try again!\n");
		exit(0);
	}
	else if (argc == 2)
	{
		ft_printf("No message to transmit. Try again!\n");
		exit(0);
	}
	server = ft_atoi(argv[1]);
	if (argc <= 0)
	{
		ft_printf("Invalid server pid provided. Try again!\n");
		exit(0);
	}
	return (server);
}

static void	init_sigaction(struct sigaction *s_action, void (*sig_handler)(int))
{
	sigemptyset(&s_action->sa_mask);
	sigaddset(&s_action->sa_mask, SIGINT);
	s_action->sa_flags = 0;
	s_action->sa_handler = sig_handler;
	sigaction(SIGUSR1, s_action, NULL);
	sigaction(SIGUSR2, s_action, NULL);
}

static void	send_data(int message, pid_t server, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		usleep(250);
		if (message & (1 << i))
			kill(server, SIGUSR1);
		else
			kill(server, SIGUSR2);
		i++;
	}
	usleep(4000);
}

int	main(int argc, char *argv[])
{
	pid_t				server;
	pid_t				client;
	struct sigaction	c_action;

	server = get_server(argc, argv);
	client = getpid();
	ft_printf("client pid: %d\n", client);
	init_sigaction(&c_action, c_sig_handler);
	while (!g_flag)
	{
		send_data(client, server, 32);
		usleep(1000);
	}	
	send_data(INT_MAX, server, 32);
	usleep(3000);
	g_flag = false;
	for (int i = 2 ; i < argc; i++)
	{
		for(int j = 0; argv[i][j] != '\0'; j++)
		{
			send_data(argv[i][j], server, 8);
			usleep(2000);
		}
		send_data('\n', server, 8);
		usleep(2000);
	}
	while (!g_flag)
	{
		send_data(0, server, 8);
		usleep(2000);
	}
}
