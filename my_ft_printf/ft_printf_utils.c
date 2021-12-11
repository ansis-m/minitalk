/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:10:39 by amalecki          #+#    #+#             */
/*   Updated: 2021/11/28 18:47:22 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_number(const char **string)
{
	int	result;

	result = **string - '0';
	while (*(*string + 1) >= '0' && *(*string + 1) <= '9')
	{
		result = result * 10 + *(*string + 1) - '0';
		(*string)++;
	}
	return (result);
}

void	init(t_data *data)
{
	data->arg = 0;
	data->conversion = '?';
	data->zero = false;
	data->dot = false;
	data->dash = false;
	data->hash = false;
	data->plus = false;
	data->space = false;
	data->width = -1;
	data->precision = -1;
}

bool	is_conversion(char ch)
{
	if ((ch == 'c') || (ch == 's') || (ch == 'p') || (ch == 'd')
		|| (ch == 'i') || (ch == 'u') || (ch == 'x') || (ch == 'X'))
		return (true);
	return (false);
}

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (*(c + i++))
		;
	return (i - 1);
}
