/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:17:21 by amalecki          #+#    #+#             */
/*   Updated: 2021/11/29 13:18:22 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_str(int lim, unsigned int n, char res[2000], int i)
{
	bool	trailing;

	trailing = false;
	while (lim)
	{
		if (n / lim || trailing)
		{
			res[i++] = n / lim + '0';
			res[i] = '\0';
			trailing = true;
		}
		n %= lim;
		lim /= 10;
	}
}

void	write_nil(char str[2000])
{
	str[0] = '0';
	str[1] = 'x';
	str[2] = '0';
	str[3] = '\0';
	str[4] = '\0';
	str[5] = '\0';
}
