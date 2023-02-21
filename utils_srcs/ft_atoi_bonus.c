/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:34:36 by rjeong            #+#    #+#             */
/*   Updated: 2023/02/21 16:42:39 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || c == ' ')
		return (1);
	return (0);
}

int	ft_cal_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (*(str + *i) == '+')
		++(*i);
	else if (*(str + *i) == '-')
	{
		sign = -1;
		++(*i);
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	while (ft_isspace(*(str + i)) && *(str + i))
		++i;
	sign = ft_cal_sign(str, &i);
	result = 0;
	if (!ft_isdigit(*(str + i)))
		ft_print_n_exit("Wrong server PID !", 2);
	while (ft_isdigit(*(str + i)))
	{
		result = result * 10 + (unsigned long long)(*(str + i) - '0');
		++i;
	}
	return ((int)(result * sign));
}
