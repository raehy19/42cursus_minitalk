/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_long_to_ascii.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:12:37 by rjeong            #+#    #+#             */
/*   Updated: 2023/01/27 22:28:47 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ul_cal_digit_dec(unsigned long long n)
{
	int	digit;

	digit = 1;
	while (n > 9)
	{
		n /= 10;
		++digit;
	}
	return (digit);
}

int	ft_cal_ultoa_dec(char *dst, int i, unsigned long long num)
{
	*(dst + i) = '0' + (num % 10);
	if (num < 10)
		return (i);
	else
		return (ft_cal_ultoa_dec(dst, i + 1, num / 10));
}

char	*ft_unsigned_long_to_ascii(unsigned long long n)
{
	char	*dst;
	int		size;

	size = 0;
	size += ft_ul_cal_digit_dec(n);
	dst = (char *) malloc (sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	ft_cal_ultoa_dec(dst, 0, n);
	*(dst + size) = '\0';
	return (ft_strrev(dst, size));
}
