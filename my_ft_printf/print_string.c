/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:31:56 by amalecki          #+#    #+#             */
/*   Updated: 2021/11/28 18:50:19 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_data(int len, t_data data, int *chars)
{
	if (data.width > len)
	{
		*chars += data.width;
		if (data.dash)
			write(1, (void *)data.arg, len);
		while (data.width-- - len)
			write(1, " ", 1);
		if (!data.dash)
			write(1, (void *)data.arg, len);
		return ;
	}
	*chars += len;
	write(1, (void *)data.arg, len);
}

void	print_string(int *chars, t_data data)
{
	int		len;
	char	*ptr;

	if (!data.arg)
	{
		if (data.dot && data.precision < 6)
			ptr = "";
		else
			ptr = "(null)";
		data.arg = (long long unsigned)ptr;
	}
	len = ft_strlen((const char *)data.arg);
	if (data.dot && data.precision < len && data.precision >= 0)
		len = data.precision;
	else if (data.dot && data.precision < len)
		len = 0;
	output_data(len, data, chars);
}
