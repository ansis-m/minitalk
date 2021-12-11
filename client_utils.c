/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:06:12 by amalecki          #+#    #+#             */
/*   Updated: 2021/12/11 18:14:30 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_strlen(char *message)
{
	int	i;

	i = 0;
	while (*(message + i++))
		;
	return (i - 1);
}

void	graceful_exit(char *message)
{
	write(1, message, ft_strlen(message));
	exit(0);
}
