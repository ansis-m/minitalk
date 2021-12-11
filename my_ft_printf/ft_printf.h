/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:34:01 by amalecki          #+#    #+#             */
/*   Updated: 2021/11/29 12:51:22 by amalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdarg.h>
# include	<stdbool.h>
# include	<stdlib.h>
# include	<stddef.h>
# include	<limits.h>
# include	<unistd.h>

typedef struct t_data
{
	long long unsigned	arg;
	char				conversion;
	bool				zero;
	bool				dot;
	bool				dash;
	bool				hash;
	bool				plus;
	bool				space;
	int					width;
	int					precision;
}	t_data;

int				ft_printf(char const *string, ...);
int				get_number(const char **string);
int				ft_strlen(const char *c);
void			init(t_data *data);
bool			is_conversion(char ch);
void			print_string(int *chars, t_data data);
void			print_char(int *chars, t_data data);
void			print_xdecimal(int *chars, t_data *data);
void			print_integer(int *chars, t_data *data);
void			print_unsigned(int *chars, t_data *data);
void			ft_write_str(int lim, unsigned int n, char res[2000], int i);
void			write_nil(char str[2000]);

#endif