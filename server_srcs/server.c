/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:38:35 by rjeong            #+#    #+#             */
/*   Updated: 2023/02/20 02:49:04 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	ft_receive(int sig)
{
	g_info.svr.counter = 0;
	if (g_info.svr.bit_idx == 8)
	{
		g_info.svr.bit_idx = 0;
		if (g_info.svr.temp)
			write(1, &g_info.svr.temp, 1);
		else
		{
			ft_printf("\n\n\033[36;40mReceive Success !\033[0m\n");
			kill(g_info.svr.client_pid, SIGUSR1);
			g_info.svr = (t_server){-1, 0, 0, 0, 0};
			return ;
		}
		g_info.svr.temp = '\0';
	}
	if (sig == SIGUSR2)
		g_info.svr.temp |= (1 << (g_info.svr.bit_idx));
	++(g_info.svr.bit_idx);
	kill(g_info.svr.client_pid, SIGUSR1);
}

static void	server_handler(int sig, siginfo_t *siginfo, ucontext_t *uap)
{
	usleep(USLEEP_SEC);
	(void)uap;
	if (sig == SIGUSR1 && g_info.svr.client_pid == -1)
	{
		g_info.svr = (t_server){siginfo->si_pid, 0, 0, 0, 1};
		ft_print_receiving(siginfo->si_pid);
		kill(g_info.svr.client_pid, SIGUSR1);
	}
	else if (siginfo->si_pid == g_info.svr.client_pid)
		ft_receive(sig);
}

int	main(void)
{
	ft_print_start_pid(SERVER);
	ft_set_sigaction(server_handler);
	g_info.svr = (t_server){-1, 0, 0, 0, 0};
	while (1)
	{
		if (++g_info.svr.counter > TIMEOUT_CNT)
		{
			if (g_info.svr.connect_flag)
			{
				ft_printf("\n\n\033[31;40mConnection Lost . . .\033[0m\n");
				kill(g_info.svr.client_pid, SIGUSR2);
			}
			g_info.svr = (t_server){-1, 0, 0, 0, 0};
		}
	}
}
