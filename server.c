/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:15:32 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/15 10:50:36 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	s_flag[2];

void	s_sig_handler(int signum)
{
	if (signum == SIGUSR1)
		s_flag[0] |= (1 << s_flag[1]);
	s_flag[1]++;
}

static void	reset(void)
{
		s_flag[0] = 0;
		s_flag[1] = 0;
}

static void	find_client(int *client)
{
	int a;

	while (s_flag[0] < 999999)
	{
		reset();
		a = get_data(31);
		if (a > 0 && a < 777777)
			*client = a;
		kill(*client, SIGUSR1);
	}	
}

int	get_data(int bits)
{
	pause();
	while (bits)
	{
		usleep(3000);
		bits--;
	}
	return (s_flag[0]);
}

int	main(void)
{
	pid_t				server;
	pid_t				client;
	struct sigaction	s_action;
	char p;

	init_sigaction(&s_action, s_sig_handler);
	server = getpid();
	ft_printf("%d\n", server);
	find_client(&client);

	printf("s_flag: %d\n", (int)s_flag[0]);
	ft_printf("client pid: %d\n", client);
	
	reset();
	p = get_data(7);
	while (p)
	{
		write(1, &p, 1);
		reset();
		kill(client, SIGUSR1);
		p = get_data(7);
	}
	kill(client, SIGUSR1);
	
}

/*
Pseudocode for server infinite loop

char *symbol;
while(true)
{
	while(!client)
	{
		get_pid()
		client = (int)s_flag;
		confirm_received(flag);
	}
	get_signal();
	while (signal not valid)
	{
		confirm_error;
		get_signal();
	}
	confirm_received;
	if(s_flag > message terminated)
	{
		confirm_received();
		client = 0;
		s_flag = 0;
		continue;
	}
	else if(s_flag == message)
	{
		symbol = (char *)&s_flag;
		printf("%c", symbol);
		s_flag = 0;
		confirm_received();
	}
}

*/