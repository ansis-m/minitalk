/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:15:32 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/11 19:35:22 by amalecki         ###   ########.fr       */
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
	while (i < 33)
	{
		pause();
		i++;
	}
}

void	init_sigaction(struct sigaction *s_action, void (*sig_handler)(int))
{
	sigemptyset(&s_action->sa_mask);
	sigaddset(&s_action->sa_mask, SIGINT);
	s_action->sa_flags = 0;
	s_action->sa_handler = s_sig_handler;
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
	printf("%d\n", server);
	get_pid();
	client = s_flag;
	printf("client pid: %d\n", client);
}
