/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:38:35 by rjeong            #+#    #+#             */
/*   Updated: 2023/01/27 21:47:37 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../ft_printf/ft_printf.h"

int	main(void)
{
	ft_printf("\033[36;40mServer start . . .\033[0;31m\nSEVER PID : ");
	ft_printf("\033[32m%d\033[0m\n", getpid());
	while (1)
	{
		;
	}
}
