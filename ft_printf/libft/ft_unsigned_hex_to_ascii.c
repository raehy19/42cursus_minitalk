/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_hex_to_ascii.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:51:55 by rjeong            #+#    #+#             */
/*   Updated: 2023/01/27 22:28:46 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cal_digit_hex(unsigned long long n)
{
	int	digit;

	digit = 1;
	while (n > 15)
	{
		n /= 16;
		++digit;
	}
	return (digit);
}

int	ft_cal_ultoa_hex(char *dst, int i, unsigned long long num, char flag)
{
	if (((num % 16) / 10) > 0)
		*(dst + i) = flag + ((num % 16) % 10);
	else
		*(dst + i) = '0' + ((num % 16) % 10);
	if (num < 16)
		return (i);
	else
		return (ft_cal_ultoa_hex(dst, i + 1, num / 16, flag));
}

char	*ft_unsigned_hex_to_ascii(unsigned long long n, char flag)
{
	char	*dst;
	int		size;

	size = 0;
	size += ft_cal_digit_hex(n);
	dst = (char *) malloc (sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	ft_cal_ultoa_hex(dst, 0, n, flag);
	*(dst + size) = '\0';
	return (ft_strrev(dst, size));
}
