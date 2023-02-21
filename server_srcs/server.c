/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:38:35 by rjeong            #+#    #+#             */
/*   Updated: 2023/02/20 02:49:04 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <stdio.h>

static void	server_handler(int sig, siginfo_t *siginfo, ucontext_t *uap)
{
	if (siginfo->si_pid == 0)
		return;
	g_info.ser.counter = 0;
	(void)uap;
	if (sig == SIGUSR1 && g_info.ser.client_pid == -1)
	{
		g_info.ser.client_pid = siginfo->si_pid;
		ft_print_receiving(siginfo->si_pid);
		kill(g_info.ser.client_pid, SIGUSR1);
	}
	else if (siginfo->si_pid == g_info.ser.client_pid)
	{
		if (g_info.ser.bit_i == 8)
		{
			g_info.ser.bit_i = 0;
			if (g_info.ser.temp)
				write(1, &g_info.ser.temp, 1);
			else
			{
				g_info.ser.client_pid = -1;
				ft_printf("\n\033[36;40mReceive Success !\033[0m\n");
				g_info.ser.last_sig = SIGUSR1;
				kill(siginfo->si_pid, SIGUSR1);
				return ;
			}
			g_info.ser.temp = '\0';
		}
		if (sig == SIGUSR2)
			g_info.ser.temp |= (1 << (g_info.ser.bit_i));
		++(g_info.ser.bit_i);
		g_info.ser.last_sig = SIGUSR1;
		kill(g_info.ser.client_pid, g_info.ser.last_sig);
	}
	else
	{
		printf("\nerror!\ninfo_client_pid : %d\nsig : %d\nsi_pid : %d\nsi_code : %d\n",g_info.ser.client_pid, sig, siginfo->si_pid, siginfo->si_code);
		kill(siginfo->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	ft_print_start_pid(SERVER);
	ft_set_sigaction(server_handler);
	g_info.ser = (t_server_info){-1, 0, 0, 0, SIGUSR1};
	while (1)
	{
		;
//		while (g_info.ser.counter < TIMEOUT_CNT)
//		{
//			while (g_info.ser.counter < WAIT_CNT)
//				++g_info.ser.counter;
//			usleep(USLEEP_SEC);
////			if (g_info.ser.client_pid != -1)
////			{
////				kill(g_info.ser.client_pid, SIGUSR1);
////				g_info.ser.counter = 0;
////			}
//		}
//		if (g_info.ser.client_pid != -1)
//		{
//			ft_printf("\n\033[34;40mTimeout !\033[0m\n");
//			g_info.ser.client_pid = -1;
//			// timeout : reset cli pid
//		}
//		g_info.ser.counter = 0;
	}
}
