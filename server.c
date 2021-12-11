/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:15:32 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/11 17:44:08 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	flag;

void	sig_handler(int signum)
{
	static int	bit;

	if (bit == 0 || bit > 32)
		bit = 1;
	if (signum == SIGUSR1)
		flag = (1 << bit | flag);
	bit++;
	// else
	// 	write(1, "received the signal 1\n", 22);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;
	int	i;

	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	action.sa_flags = 0;
	action.sa_handler = sig_handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	pid = getpid();
	printf("%d\n", pid);

	//signal(SIGUSR1, sig_handler);
	//signal(SIGUSR2, sig_handler);

	printf("server\n");
	pause();
	for(i = 1; i < 33 ; i++)
	{
		pause();
	}
	printf("i: %d\n", flag);
}
