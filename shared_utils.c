/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 08:30:59 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/12 08:33:39 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_sigaction(struct sigaction *s_action, void (*sig_handler)(int))
{
	sigemptyset(&s_action->sa_mask);
	sigaddset(&s_action->sa_mask, SIGINT);
	s_action->sa_flags = 0;
	s_action->sa_handler = s_sig_handler;
	sigaction(SIGUSR1, s_action, NULL);
	sigaction(SIGUSR2, s_action, NULL);
}
