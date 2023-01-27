/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:15:27 by rjeong            #+#    #+#             */
/*   Updated: 2023/01/27 21:47:28 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_type(t_flag *flag, char c)
{
	const char	*types = "csdiuxXp";
	int			i;

	i = -1;
	while (++i < 8)
		if (*(types + i) == c)
			flag->type = i;
	return ;
}

void	ft_check_precision(t_flag *flag, const char *input, int *i)
{
	int	temp;

	temp = 0;
	if (*(input + (++(*i))) == '-')
		return ;
	while (ft_isdigit(*(input + (*i))))
	{
		temp = temp * 10 + (*(input + (*i)) - '0');
		++(*i);
	}
	flag->precision = temp;
	--(*i);
	return ;
}

void	ft_check_min_width(t_flag *flag, const char *input, int *i)
{
	int	temp;

	temp = 0;
	while (ft_isdigit(*(input + (*i))))
	{
		temp = temp * 10 + (*(input + (*i)) - '0');
		++(*i);
	}
	flag->min_width = temp;
	--(*i);
	return ;
}
