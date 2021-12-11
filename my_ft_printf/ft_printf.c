/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:31:00 by amalecki          #+#    #+#             */
/*   Updated: 2021/11/29 12:50:38 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sort_and_print(int *chars, t_data *data)
{
	if (data->conversion == 's')
		print_string(chars, *data);
	if (data->conversion == 'c')
		print_char(chars, *data);
	if (data->conversion == 'd' || data->conversion == 'i')
		print_integer(chars, data);
	if (data->conversion == 'u' )
		print_unsigned(chars, data);
	if (data->conversion == 'x' || data->conversion == 'X' )
		print_xdecimal(chars, data);
	if (data->conversion == 'p')
	{
		data->hash = true;
		print_xdecimal(chars, data);
	}
	return (1);
}

static int	get_flags(const char **string, va_list args,
int *chars, t_data *data)
{
	while (!is_conversion(**string))
	{
		if (**string == '.')
			data->dot = true;
		else if (**string == '%')
			return (*chars += write(1, "%", 1));
		else if (**string == '-')
			data->dash = true;
		else if (**string == '#')
			data->hash = true;
		else if (**string == '+')
			data->plus = true;
		else if (**string == ' ' && !data->dot)
			data->space = true;
		else if (**string == '0' && !data->dot)
			data->zero = true;
		else if (**string >= '0' && **string <= '9' && data->dot)
			data->precision = get_number(string);
		else if (**string >= '1' && **string <= '9' && !data->dot)
			data->width = get_number(string);
		(*string)++;
	}
	data->conversion = **string;
	data->arg = va_arg(args, long long);
	return (sort_and_print(chars, data));
}

static void	parse_string(char const *string, va_list args, int *chars)
{
	t_data	data;

	while (*string)
	{
		if (*string == '%' && *(string + 1))
		{
			init(&data);
			string++;
			get_flags(&string, args, chars, &data);
		}	
		else
		{
			write(1, string, 1);
			(*chars)++;
		}
		string++;
	}
}

int	ft_printf(char const *string, ...)
{
	int		chars;
	va_list	args;

	va_start(args, string);
	chars = 0;
	parse_string(string, args, &chars);
	va_end(args);
	return (chars);
}
