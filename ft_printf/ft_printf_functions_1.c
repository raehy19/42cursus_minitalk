/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:33:37 by rjeong            #+#    #+#             */
/*   Updated: 2023/01/27 21:48:44 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_percent(t_flag *flag)
{
	if (flag->align_left == 0)
		if (ft_print_space(flag->fill_zero, flag->min_width - 1) < 0)
			return (-1);
	if (write(1, "%", 1) < 0)
		return (-1);
	if (flag->align_left == 1)
		if (ft_print_space(0, flag->min_width - 1) < 0)
			return (-1);
	return (ft_max(flag->min_width, 1));
}

int	ft_type_character(va_list ap, t_flag *flag)
{
	char	c;

	c = (char) va_arg(ap, int);
	if (flag->align_left == 0)
		if (ft_print_space(0, flag->min_width - 1) < 0)
			return (-1);
	if (write(1, &c, 1) < 0)
		return (-1);
	if (flag->align_left == 1)
		if (ft_print_space(0, flag->min_width - 1) < 0)
			return (-1);
	return (ft_max(flag->min_width, 1));
}

int	ft_type_string(va_list ap, t_flag *flag)
{
	const char	*null_str = "(null)";
	char		*str;
	int			len;

	str = (char *) va_arg(ap, char *);
	if (!str)
		str = (char *) null_str;
	len = ft_strlen(str);
	if (flag->precision > -1 && flag->precision < len)
		len = flag->precision;
	if (flag->align_left == 0)
		if (ft_print_space(0, flag->min_width - len) < 0)
			return (-1);
	if (write(1, str, len) < 0)
		return (-1);
	if (flag->align_left == 1)
		if (ft_print_space(0, flag->min_width - len) < 0)
			return (-1);
	return (ft_max(flag->min_width, len));
}

int	ft_type_int(va_list ap, t_flag *flag)
{
	long long	n;
	char		*str;
	int			len;

	n = (long long) va_arg(ap, int);
	str = ft_long_to_ascii(n);
	if (!str)
		return (-1);
	if (flag->precision == 0 && *str == '0')
	{
		free(str);
		return (ft_print_precision_zero(flag));
	}
	if (flag->precision > -1)
		flag->fill_zero = 0;
	len = ft_strlen(str);
	if (*str == '-')
		return (ft_print_num_minus(str, len, flag));
	return (ft_print_num_plus(str, len, flag));
}
