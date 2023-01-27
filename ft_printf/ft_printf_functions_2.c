/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:02:52 by rjeong            #+#    #+#             */
/*   Updated: 2023/01/27 21:47:25 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_unsigned_int(va_list ap, t_flag *flag)
{
	unsigned long long	n;
	char				*str;
	int					len;

	n = (unsigned long long) va_arg(ap, unsigned int);
	str = ft_unsigned_long_to_ascii(n);
	if (!str)
		return (-1);
	if (flag->precision == 0 && *str == '0')
	{
		free(str);
		if (flag->min_width > 0)
			return (ft_print_space(0, flag->min_width));
		return (0);
	}
	if (flag->precision > -1)
		flag->fill_zero = 0;
	len = ft_strlen(str);
	return (ft_print_unsigned(str, len, flag));
}

int	ft_type_hex_lower(va_list ap, t_flag *flag)
{
	unsigned long long	n;
	char				*str;
	int					len;

	n = (unsigned long long) va_arg(ap, unsigned int);
	str = ft_unsigned_hex_to_ascii(n, 'a');
	if (!str)
		return (-1);
	if (flag->precision == 0 && *str == '0')
	{
		free(str);
		if (flag->min_width > 0)
			return (ft_print_space(0, flag->min_width));
		return (0);
	}
	if (flag->precision > -1)
		flag->fill_zero = 0;
	len = ft_strlen(str);
	if (flag->display_zero_x == 1 && *(str) != '0')
		return (ft_print_pointer(str, len, flag, "0x"));
	return (ft_print_unsigned(str, len, flag));
}

int	ft_type_hex_upper(va_list ap, t_flag *flag)
{
	unsigned long long	n;
	char				*str;
	int					len;

	n = (unsigned long long) va_arg(ap, unsigned int);
	str = ft_unsigned_hex_to_ascii(n, 'A');
	if (!str)
		return (-1);
	if (flag->precision == 0 && *str == '0')
	{
		free(str);
		if (flag->min_width > 0)
			return (ft_print_space(0, flag->min_width));
		else
			return (0);
	}
	if (flag->precision > -1)
		flag->fill_zero = 0;
	len = ft_strlen(str);
	if (flag->display_zero_x == 1 && *(str) != '0')
		return (ft_print_pointer(str, len, flag, "0X"));
	return (ft_print_unsigned(str, len, flag));
}

int	ft_type_pointer(va_list ap, t_flag *flag)
{
	unsigned long long	n;
	char				*str;
	int					len;

	n = (unsigned long long) va_arg(ap, unsigned int *);
	str = ft_unsigned_hex_to_ascii(n, 'a');
	if (!str)
		return (-1);
	len = ft_strlen(str);
	return (ft_print_pointer(str, len, flag, "0x"));
}
