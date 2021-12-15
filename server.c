/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:15:32 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/15 16:17:13 by amalecki         ###   ########.fr       */
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

static void	find_client(int *client)
{
	while (s_flag[0] < 999999)
	{
		s_flag[0] = 0;
		s_flag[1] = 0;
		get_data(31);
		if (s_flag[0] > 0 && s_flag[0] < 777777)
			*client = s_flag[0];
		kill(*client, SIGUSR1);
	}
	s_flag[0] = 0;
	s_flag[1] = 0;
}

int	get_data(int bits)
{
	s_flag[0] = 0;
	s_flag[1] = 0;
	pause();
	while (bits)
	{
		usleep(3000);
		bits--;
	}
	return (s_flag[0]);
}

void	init_sigaction(struct sigaction *s_action, void (*sig_handler)(int))
{
	sigemptyset(&s_action->sa_mask);
	sigaddset(&s_action->sa_mask, SIGINT);
	s_action->sa_flags = 0;
	s_action->sa_handler = sig_handler;
	sigaction(SIGUSR1, s_action, NULL);
	sigaction(SIGUSR2, s_action, NULL);
}

int	main(void)
{
	pid_t				server;
	pid_t				client;
	struct sigaction	s_action;

	init_sigaction(&s_action, s_sig_handler);
	server = getpid();
	ft_printf("%d\n", server);
	while (true)
	{
		find_client(&client);
		get_data(7);
		while (s_flag[0])
		{
			write(1, &s_flag[0], 1);
			kill(client, SIGUSR2);
			get_data(7);
		}
		kill(client, SIGUSR1);
	}
}
