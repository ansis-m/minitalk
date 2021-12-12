/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:15:32 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/12 09:16:30 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	s_flag;

void	s_sig_handler(int signum)
{
	static int	bit;

	if (bit == 0 || bit > 32 || s_flag == -9999)
	{
		bit = 1;
		s_flag = 0;
	}
	if (signum == SIGUSR1)
		s_flag = (1 << bit | s_flag);
	bit++;
}

void	get_pid(void)
{
	int	i;

	i = 1;
	pause();
	while (i < 33)
	{
		usleep(250);
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
	get_pid();
	client = s_flag;
	ft_printf("client pid: %d\n", client);
	
	for (int i = 0 ; i < 200; i++)
	{
		kill(client, SIGUSR1);
		usleep(200);
	}
		kill(client, SIGUSR1);
	
}
