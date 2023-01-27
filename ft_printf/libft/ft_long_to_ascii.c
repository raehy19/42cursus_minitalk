/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_to_ascii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:23:02 by rjeong            #+#    #+#             */
/*   Updated: 2023/01/27 22:28:35 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_l_cal_digit_dec(long long n)
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

int	ft_cal_ltoa_dec(char *dst, int i, long long num)
{
	*(dst + i) = '0' + (num % 10);
	if (num < 10)
		return (i);
	else
		return (ft_cal_ltoa_dec(dst, i + 1, num / 10));
}

char	*ft_long_to_ascii(long long n)
{
	char	*dst;
	int		size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		++size;
	}
	size += ft_l_cal_digit_dec(n);
	dst = (char *) malloc (sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	if (ft_cal_ltoa_dec(dst, 0, n) + 1 < size)
		*(dst + size - 1) = '-';
	*(dst + size) = '\0';
	return (ft_strrev(dst, size));
}
