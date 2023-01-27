/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:15:00 by rjeong            #+#    #+#             */
/*   Updated: 2023/01/27 22:28:41 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str, long long len)
{
	long long	i;
	char		temp;

	i = 0;
	while (i < len - 1 - i)
	{
		temp = *(str + i);
		*(str + i) = *(str + len - 1 - i);
		*(str + len - 1 - i) = temp;
		++i;
	}
	return (str);
}
