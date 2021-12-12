/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 08:45:28 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/12 08:47:50 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	init_sigaction(struct sigaction *s_action, void (*sig_handler)(int))
{
	sigemptyset(&s_action->sa_mask);
	sigaddset(&s_action->sa_mask, SIGINT);
	s_action->sa_flags = 0;
	s_action->sa_handler = sig_handler;
	sigaction(SIGUSR1, s_action, NULL);
	sigaction(SIGUSR2, s_action, NULL);
}