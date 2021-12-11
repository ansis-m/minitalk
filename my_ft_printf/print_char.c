/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:32:07 by amalecki          #+#    #+#             */
/*   Updated: 2021/11/27 09:52:18 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int *chars, t_data data)
{
	if (data.width > 1)
	{
		(*chars) += data.width;
		if (data.dash)
			write(1, &data.arg, 1);
		while (--data.width)
			write(1, " ", 1);
		if (!data.dash)
			write(1, &data.arg, 1);
	}
	else
	{
		write(1, &data.arg, 1);
		(*chars)++;
	}
}
