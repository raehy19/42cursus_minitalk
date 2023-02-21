/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:38:49 by rjeong            #+#    #+#             */
/*   Updated: 2023/02/20 02:49:51 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	client_handler(int sig, siginfo_t *siginfo, ucontext_t *uap)
{
	g_info.cli.counter = 0;
	(void)uap;
	if (sig == SIGUSR1 && siginfo->si_pid == g_info.cli.server_pid)
	{
		if (g_info.cli.bit_i == 8)
		{
			g_info.cli.bit_i = 0;
			if ((*(g_info.cli.msg + g_info.cli.msg_i)) == 0)
			{
				g_info.cli.last_sig = SIGUSR1;
				kill(g_info.cli.server_pid, g_info.cli.last_sig);
				exit(0);
			}
			++g_info.cli.msg_i;
		}
		g_info.cli.last_sig = SIGUSR1;
		if ((*(g_info.cli.msg + g_info.cli.msg_i)) & (1 << (g_info.cli.bit_i)))
			g_info.cli.last_sig = SIGUSR2;
		++(g_info.cli.bit_i);
		kill(g_info.cli.server_pid, g_info.cli.last_sig);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		ft_print_n_exit("Wrong arguments !", 1);
	ft_print_start_pid(CLIENT);
	ft_set_sigaction(client_handler);
	g_info.cli = (t_client_info){ft_atoi((const char *)*(av + 1)), *(av + 2), 0, 0, 0, 0};
	ft_print_pid_msg(g_info.cli.server_pid, g_info.cli.msg);
	if (kill(g_info.cli.server_pid, SIGUSR1) < 0)
		ft_print_n_exit("Can't connect to server !", 3);
	while (g_info.cli.counter < TIMEOUT_CNT)
	{
		while (g_info.cli.counter < WAIT_CNT)
			++g_info.cli.counter;
		usleep(USLEEP_SEC);
		kill(g_info.cli.server_pid, g_info.cli.last_sig);
		ft_printf("resending\n");
		// no response : kill last sig again
	}
	ft_print_n_exit("Timeout !", 4);
}
