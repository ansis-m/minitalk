/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:16:37 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/13 14:08:13 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

long long	c_flag;

void	c_sig_handler(int signum)
{
	ft_printf("communication established\n");
	if (signum == SIGUSR1)
		c_flag = 1;
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
		usleep(100);
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
	while (c_flag != 1)
	{
		send_pid(client, server);
		usleep(3000);
	}	
	usleep(2000);
	send_pid(INT_MAX, server);

	pause();
}

/*
Pseudocode for client

send_pid();

while(c_flag = pid_not confirmed)
{
	send_pid();
	usleep(1000);
}
reset(c_flag);
for (int i =2 ; i < argc; i++)
{
	for(int j = 0; argv[i][j] != '\0', j++)
	{
		send_char()
		while(c_flag = char_not confirmed)
		{
			send_char();
		}
		reset(c_flag);
	}
}

send_terminating_code()
while(c_flag = not confirmed)
	send_terminating_code()

*/
