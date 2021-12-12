/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:16:56 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/12 08:36:37 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<signal.h>
# include	<stdbool.h>
# include	<stdio.h>//TO BE REMOVED //TO BE REMOVED //TO BE REMOVED
# include	<wchar.h> //TO BE REMOVED //TO BE REMOVED //TO BE REMOVED
# include	<locale.h>  //TO BE REMOVED //TO BE REMOVED //TO BE REMOVED

int		ft_printf(char const *string, ...);
void	init_sigaction(struct sigaction *s_action, void (*sig_handler)(int));

#endif