/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:16:37 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/15 11:17:55 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

long long	c_flag;

void	c_sig_handler(int signum)
{
	if (signum == SIGUSR1)
		c_flag = 1;
}

void	send_pid(pid_t client, pid_t server)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (client & (1 << i))
			kill(server, SIGUSR1);
		else
			kill(server, SIGUSR2);
		usleep(300);
		i++;
	}
	usleep(4000);
}

void	send_char(char message, pid_t server)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(350);
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

	if (argc == 1)
		graceful_exit("No pid provided to client. Try again!\n");
	server = atoi(argv[1]);
	client = getpid();
	ft_printf("client pid: %d\n", client);
	init_sigaction(&c_action, c_sig_handler);
	while (c_flag != 1)
	{
		send_pid(client, server);
		usleep(1000);
	}	
	usleep(2000);
	send_pid(INT_MAX, server);

	usleep(3000);
	usleep(3000);
	
	c_flag = 0;
	for (int i = 2 ; i < argc; i++)
	{
		for(int j = 0; argv[i][j] != '\0'; j++)
		{
			send_char(argv[i][j], server);
			usleep(2000);
		}
		send_char('\n', server);
		usleep(2000);
	}
	while(!c_flag)
	{
		send_char(0, server);
		usleep(2000);
	}
		
}
//cat ./big.txt | xargs -0 ./client 15978
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
