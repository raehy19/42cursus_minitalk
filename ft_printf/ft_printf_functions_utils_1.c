/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_utils_1.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:45:30 by rjeong            #+#    #+#             */
/*   Updated: 2023/01/27 21:47:11 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_free_n_return(void *p, int value)
{
	free (p);
	return (value);
}

int	ft_print_space(int is_zero, int count)
{
	char	space;
	int		i;

	space = ' ';
	if (is_zero == 1)
		space = '0';
	i = -1;
	while (++i < count)
		if (write(1, &space, 1) < 0)
			return (-1);
	return (ft_max(count, 0));
}

int	ft_print_unsigned(char *str, int len, t_flag *flag)
{
	if (flag->precision > len)
		len = flag->precision;
	if (flag->align_left == 0)
		if (ft_print_space(flag->fill_zero, flag->min_width - len) < 0)
			return (ft_free_n_return(str, -1));
	if (ft_print_space(1, flag->precision - (ft_strlen(str))) < 0)
		return (ft_free_n_return(str, -1));
	if (write(1, str, ft_strlen(str)) < 0)
		return (ft_free_n_return(str, -1));
	if (flag->align_left == 1)
		if (ft_print_space(0, flag->min_width - len) < 0)
			return (ft_free_n_return(str, -1));
	return (ft_free_n_return(str, ft_max(flag->min_width, len)));
}

int	ft_print_pointer(char *str, int len, t_flag *flag, char *zero_x)
{
	if (flag->precision > len)
		len = flag->precision;
	if (flag->align_left == 0 && flag->fill_zero == 0)
		if (ft_print_space(flag->fill_zero, flag->min_width - len - 2) < 0)
			return (ft_free_n_return(str, -1));
	if (write (1, zero_x, 2) < 0)
		return (ft_free_n_return(str, -1));
	if (flag->align_left == 0 && flag->fill_zero == 1)
		if (ft_print_space(flag->fill_zero, flag->min_width - len - 2) < 0)
			return (ft_free_n_return(str, -1));
	if (ft_print_space(1, flag->precision - (ft_strlen(str))) < 0)
		return (ft_free_n_return(str, -1));
	if (write(1, str, ft_strlen(str)) < 0)
		return (ft_free_n_return(str, -1));
	if (flag->align_left == 1)
		if (ft_print_space(0, flag->min_width - len - 2) < 0)
			return (ft_free_n_return(str, -1));
	return (ft_free_n_return(str, ft_max(flag->min_width, len + 2)));
}
