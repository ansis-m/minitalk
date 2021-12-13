/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:15:32 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/13 11:35:21 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	s_flag;

void	s_sig_handler(int signum)
{
	static int	bit;
	ft_printf("s_flag: %d   bit: %d\n", s_flag, bit);
	if (bit == 0 || bit > 32 || s_flag == -999)
	{
		bit = 1;
		s_flag = 0;
	}
	if (signum == SIGUSR1)
		s_flag += (1 << bit);
	bit++;
}

void	get_pid(void)
{
	int	i;

	i = 1;
	pause();
	while (i < 33)
	{
		usleep(6000);
		i++;
	}
}

int	main(void)
{
	pid_t				server;
	pid_t				client;
	struct sigaction	s_action;

	init_sigaction(&s_action, s_sig_handler);
	server = getpid();
	ft_printf("%d\n", server);
	s_flag = -999;
	client = 0;
	while (s_flag < 999999)
	{
		s_flag = -999;
		get_pid();
		if (s_flag > 0 && s_flag < 777777)
			client = (int)s_flag;
		s_flag = -999;
		kill(client, SIGUSR1);
		get_pid();
	}	


	ft_printf("client pid: %d\n", client);
	// for (int i = 0 ; i < 200; i++)
	// {
	// 	kill(client, SIGUSR1);
	// 	usleep(200);
	// }
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
	while (signal not valid)
	{
		confirm_error;
		get_signal();
	}
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