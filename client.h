/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:17:02 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/16 10:47:51 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<signal.h>
# include	<stdbool.h>
# include	<limits.h>

int		ft_strlen(char *message);
int		ft_atoi(const char *nptr);
int		ft_printf(char const *string, ...);

#endif