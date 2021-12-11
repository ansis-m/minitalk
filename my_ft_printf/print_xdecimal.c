/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xdecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:32:14 by amalecki          #+#    #+#             */
/*   Updated: 2021/11/29 12:19:03 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pad_a_xdec(char string[2000], int precision, int len)
{
	int	diff;

	if (string[1] == 'x' || string[1] == 'X')
	{
		string += 2;
		len -= 2;
	}
	diff = precision - len;
	while (len >= 0)
	{
		string[len + diff] = string[len];
		len--;
	}
	while (--diff >= 0)
		string[diff] = '0';
}

static void	convert_to_int(long long unsigned *arg)
{
	*arg = *arg << 32;
	*arg = *arg >> 32;
}

static void	write_hexadec(t_data data, char str[2000], const char *symbols)
{
	bool				trailing;
	long long unsigned	lim;

	lim = (long long unsigned)1 << 60;
	str[0] = '\0';
	if (data.arg == 0 && data.dot && data.precision < 1
		&& (data.conversion == 'x' || data.conversion == 'X'))
		return ;
	str[0] = '0';
	str[1] = '\0';
	if (data.conversion == 'x' || data.conversion == 'X')
		convert_to_int(&data.arg);
	trailing = false;
	while (lim)
	{
		if (data.arg / lim || trailing)
		{
			*(str++) = symbols[data.arg / lim];
			*str = '\0';
			trailing = true;
		}
		data.arg %= lim;
		lim = lim >> 4;
	}
}

static void	organize_data(t_data *data, char str[2000], char *f)
{
	if (data->conversion == 'p' && data->arg == 0)
		write_nil(str);
	else if (data->conversion == 'p' || (data->conversion == 'x'
			&& data->hash && (int)data->arg))
	{
		str[0] = '0';
		str[1] = 'x';
		write_hexadec(*data, str + 2, "0123456789abcdef");
	}
	else if (data->conversion == 'X' && data->hash && (int)data->arg)
	{
		str[0] = '0';
		str[1] = 'X';
		write_hexadec(*data, str + 2, "0123456789ABCDEF");
	}
	else if (data->conversion == 'X')
		write_hexadec(*data, str, "0123456789ABCDEF");
	else if (data->conversion == 'x' || data->conversion == 'p')
		write_hexadec(*data, str, "0123456789abcdef");
	*f = ' ';
	if (data->zero && ft_strlen(str) && !data->dot)
		*f = '0';
}

void	print_xdecimal(int *chars, t_data *data)
{
	char	string[2000];
	int		len;
	int		spaces;
	char	filler;

	organize_data(data, string, &filler);
	if (ft_strlen((const char *)string) < data->precision)
		pad_a_xdec(string, data->precision, ft_strlen((const char *)string));
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
