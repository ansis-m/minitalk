/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:16:37 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/11 17:45:24 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"


int	main(int argc, char *argv[])
{
	pid_t	server;
	pid_t	client;

	if(argc == 1)
	{
		printf("client missing pid\n");
		exit(0);
	}

	server = atoi(argv[1]);
	client = getpid();
	printf("client pid: %d\n", client);
	int k = 99998765;
	for(int i = 1; i < 33; i++)
	{
		if(k & (1 << i))
			kill(server, SIGUSR1);
		else
			kill(server, SIGUSR2);
		usleep(500);
	}
	kill(server, SIGUSR2);
}
