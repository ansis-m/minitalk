/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:17:02 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/11 20:03:32 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<signal.h>
# include	<stdbool.h>
# include	<stdio.h>//TO BE REMOVED //TO BE REMOVED //TO BE REMOVED

void	graceful_exit(char *message);
int		ft_strlen(char *message);
int		ft_printf(char const *string, ...);

#endif