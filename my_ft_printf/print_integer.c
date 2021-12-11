/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:31:37 by amalecki          #+#    #+#             */
/*   Updated: 2021/11/29 12:38:35 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_itoa1(t_data data, char result[2000])
{
	int		index;
	int		limit;
	int		n;

	index = 0;
	n = (int)data.arg;
	if (n == 0 && data.dot && data.precision < 1)
	{
		result[0] = '\0';
		return ;
	}
	if (n < 0)
	{
		result[index++] = '-';
		n = -n;
	}
	result[index] = '0';
	result[index + 1] = '\0';
	limit = 1000000000;
	ft_write_str(limit, n, result, index);
}

static void	organize_data(t_data *data, char str[2000], char **ptr, char *f)
{
	if (data->dot || data->dash)
		data->zero = false;
	if (data->plus || (int)data->arg < 0)
		data->space = false;
	if (data->plus && (int)data->arg >= 0 && !data->zero)
	{
		str[0] = '+';
		(*ptr)++;
	}
	if (data->space)
	{
		str[0] = ' ';
		(*ptr)++;
	}
	if (!(data->precision == 0 && (int)data->arg == 0))
		ft_itoa1(*data, *ptr);
	else
		**ptr = '\0';
	if (data->zero)
		*f = '0';
	else
		*f = ' ';
}

static void	pad_a_string(char string[2000], int precision, int len)
{
	int	diff;

	diff = precision - len;
	if (string[0] == '+' || string[0] == '-')
	{
		string += 1;
		len -= 1;
		diff++;
	}
	while (len >= 0)
	{
		string[len + diff] = string[len];
		len--;
	}
	while (--diff >= 0)
		string[diff] = '0';
}

static void	write_int_string(t_data *data, char string[200], char f, int *chars)
{
	int		spaces;	

	if (data->width > ft_strlen((const char *)string))
	{
		spaces = data->width - ft_strlen((const char *)string);
		*chars += data->width;
		if (data->dash)
			write(1, string, ft_strlen((const char *)string));
		if (data->plus && data->zero && !data->dash && spaces--)
			write(1, "+", 1);
		while (spaces--)
			write(1, &f, 1);
		if (!data->dash)
			write(1, string, ft_strlen((const char *)string));
		return ;
	}
	*chars += ft_strlen((const char *)string);
	write(1, string, ft_strlen((const char *)string));
}

void	print_integer(int *chars, t_data *data)
{
	char	string[2000];
	char	*pointer;
	char	filler;

	pointer = string;
	organize_data(data, string, &pointer, &filler);
	if (ft_strlen((const char *)string) <= data->precision)
		pad_a_string(string, data->precision, ft_strlen((const char *)string));
	if (data->zero && data->width >= ft_strlen((const char *)string)
		&& (string[0] == '-' || string[0] == '+'))
		pad_a_string(string, data->width - 1, ft_strlen((const char *)string));
	write_int_string(data, string, filler, chars);
}
