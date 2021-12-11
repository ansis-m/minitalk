/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:31:49 by amalecki          #+#    #+#             */
/*   Updated: 2021/11/28 20:05:48 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_itoa1(t_data data, char result[2000])
{
	int		index;
	int		limit;
	int		n;

	index = 0;
	n = (unsigned int)data.arg;
	if (n == 0 && data.dot && data.precision < 1)
	{
		result[0] = '\0';
		return ;
	}
	result[index] = '0';
	result[index + 1] = '\0';
	limit = 1000000000;
	ft_write_str(limit, n, result, index);
}

static void	pad_a_string(char string[2000], int precision, int len)
{
	int	diff;

	diff = precision - len;
	while (len >= 0)
	{
		string[len + diff] = string[len];
		len--;
	}
	while (--diff >= 0)
		string[diff] = '0';
}

static void	organize_data(t_data *data, char **ptr, char *f)
{
	if (data->dot || data->dash)
		data->zero = false;
	if (data->plus)
		data->space = false;
	if (!(data->precision == 0 && (int)data->arg == 0))
		ft_itoa1(*data, *ptr);
	else
		**ptr = '\0';
	if (data->zero)
		*f = '0';
	else
		*f = ' ';
}

void	print_unsigned(int *chars, t_data *data)
{
	char	string[2000];
	char	*pointer;
	int		len;
	int		spaces;
	char	filler;

	pointer = string;
	organize_data(data, &pointer, &filler);
	if (ft_strlen((const char *)string) < data->precision)
		pad_a_string(string, data->precision, ft_strlen((const char *)string));
	len = ft_strlen((const char *)string);
	if (data->width > len)
	{
		spaces = data->width - len;
		*chars += data->width;
		if (data->dash)
			write(1, string, len);
		while (spaces--)
			write(1, &filler, 1);
		if (!data->dash)
			write(1, string, len);
		return ;
	}
	*chars += len;
	write(1, string, len);
}
