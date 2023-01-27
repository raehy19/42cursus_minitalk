/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_utils_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:54:42 by rjeong            #+#    #+#             */
/*   Updated: 2023/01/27 21:47:26 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_precision_zero(t_flag *flag)
{
	const char	*sign = "+ ";

	if (flag->display_sign == 0)
		return (ft_print_space(0, flag->min_width));
	if (flag->align_left == 0)
		if (ft_print_space(0, flag->min_width - 1) < 0)
			return (-1);
	if (write (1, sign + flag->display_sign - 1, 1) < 0)
		return (-1);
	if (flag->align_left == 1)
		if (ft_print_space(0, flag->min_width - 1) < 0)
			return (-1);
	return (ft_max(flag->min_width, 1));
}

int	ft_print_num_minus(char *str, int len, t_flag *flag)
{
	if (flag->precision + 1 > len)
		len = flag->precision + 1;
	if (flag->fill_zero == 1)
		if (write(1, "-", 1) < 0)
			return (ft_free_n_return(str, -1));
	if (flag->align_left == 0)
		if (ft_print_space(flag->fill_zero, flag->min_width - len) < 0)
			return (ft_free_n_return(str, -1));
	if (flag->fill_zero == 0)
		if (write(1, "-", 1) < 0)
			return (ft_free_n_return(str, -1));
	if (ft_print_space(1, flag->precision - (ft_strlen(str) - 1)) < 0)
		return (ft_free_n_return(str, -1));
	if (write(1, str + 1, ft_strlen(str) - 1) < 0)
		return (ft_free_n_return(str, -1));
	if (flag->align_left == 1)
		if (ft_print_space(0, flag->min_width - len) < 0)
			return (ft_free_n_return(str, -1));
	return (ft_free_n_return(str, ft_max(flag->min_width, len)));
}

int	ft_print_num_plus(char *str, int len, t_flag *flag)
{
	const char	*sign = "+ ";

	if (flag->display_sign == 0)
		return (ft_print_unsigned(str, len, flag));
	if (flag->precision > len)
		len = flag->precision;
	if (flag->fill_zero == 1)
		if (write(1, sign + flag->display_sign - 1, 1) < 0)
			return (ft_free_n_return(str, -1));
	if (flag->align_left == 0)
		if (ft_print_space(flag->fill_zero, flag->min_width - len - 1) < 0)
			return (ft_free_n_return(str, -1));
	if (flag->fill_zero == 0)
		if (write(1, sign + flag->display_sign - 1, 1) < 0)
			return (ft_free_n_return(str, -1));
	if (ft_print_space(1, flag->precision - ft_strlen(str)) < 0)
		return (ft_free_n_return(str, -1));
	if (write(1, str, ft_strlen(str)) < 0)
		return (ft_free_n_return(str, -1));
	if (flag->align_left == 1)
		if (ft_print_space(0, flag->min_width - len - 1) < 0)
			return (ft_free_n_return(str, -1));
	return (ft_free_n_return(str, ft_max(flag->min_width, len + 1)));
}
