/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:38:35 by rjeong            #+#    #+#             */
/*   Updated: 2023/02/08 21:22:53 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../ft_printf/ft_printf.h"

void	ft_init_sigaction(void)
{
	struct sigaction	sigaction;

	(void)sigaction;
}

int	main(void)
{
	ft_printf("\033[36;40mServer start . . .\033[0;31m\nSEVER PID : ");
	ft_printf("\033[32m%d\033[0m\n", getpid());
	while (1)
	{
		pause();
	}
}
