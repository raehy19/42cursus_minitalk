/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:20:46 by rjeong            #+#    #+#             */
/*   Updated: 2023/01/27 21:47:15 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choose_functions(int i, va_list ap, t_flag *flag)
{
	int	(*functions[8])(va_list, t_flag *);

	functions[0] = ft_type_character;
	functions[1] = ft_type_string;
	functions[2] = ft_type_int;
	functions[3] = ft_type_int;
	functions[4] = ft_type_unsigned_int;
	functions[5] = ft_type_hex_lower;
	functions[6] = ft_type_hex_upper;
	functions[7] = ft_type_pointer;
	if (i > 7)
		return (-1);
	return (functions[i](ap, flag));
}

int	ft_parsing(const char *input, int *i, va_list ap)
{
	t_flag	flag;

	flag = (t_flag){-1, 0, -1, 0, 0, 0, 0};
	while (flag.type == -1 && *(input + (++(*i))) != '\0')
	{
		if (*(input + (*i)) == '%')
			return (ft_type_percent(&flag));
		else if (*(input + (*i)) == '-')
			flag.align_left = 1;
		else if (*(input + (*i)) == '0')
			flag.fill_zero = 1;
		else if (*(input + (*i)) == '.')
			ft_check_precision(&flag, input, i);
		else if (*(input + (*i)) == '+')
			flag.display_sign = 1;
		else if (*(input + (*i)) == ' ')
			flag.display_sign = 2;
		else if (*(input + (*i)) == '#')
			flag.display_zero_x = 1;
		else if (ft_isdigit(*(input + (*i))))
			ft_check_min_width(&flag, input, i);
		else
			ft_check_type(&flag, *(input + (*i)));
	}
	return (ft_choose_functions(flag.type, ap, &flag));
}

int	ft_check_format(const char *input, int *i, int *print_size, va_list ap)
{
	int	write_size;

	if (*(input + (*i)) == '%')
	{
		write_size = ft_parsing(input, i, ap);
		if (write_size < 0)
		{
			*(print_size) = -1;
			return (-1);
		}
		*(print_size) += write_size;
	}
	else
	{
		write_size = write(1, input + (*i), 1);
		if (write_size < 0)
		{
			*(print_size) = -1;
			return (-1);
		}
		*(print_size) += write_size;
	}
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		print_size;
	int		i;

	va_start(ap, input);
	print_size = 0;
	i = -1;
	while (*(input + (++i)) != '\0')
	{
		if (ft_check_format(input, &i, &print_size, ap) < 0
			|| print_size < 0)
			break ;
	}
	va_end(ap);
	return (print_size);
}
