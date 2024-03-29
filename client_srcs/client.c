/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:38:49 by rjeong            #+#    #+#             */
/*   Updated: 2023/02/20 02:49:51 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

extern t_g_info	g_info;

static void	client_handler(int sig, siginfo_t *siginfo, ucontext_t *uap)
{
	g_info.cli.counter = 0;
	usleep(USLEEP_SEC);
	(void)uap;
	if (sig == SIGUSR1 && siginfo->si_pid == g_info.cli.server_pid)
	{
		if (g_info.cli.bit_idx == 8)
		{
			g_info.cli.bit_idx = 0;
			if ((*(g_info.cli.msg + g_info.cli.msg_idx)) == 0)
			{
				kill(g_info.cli.server_pid, SIGUSR1);
				ft_print_n_exit("Send Success !", 0);
			}
			++g_info.cli.msg_idx;
		}
		if ((*(g_info.cli.msg + g_info.cli.msg_idx))
			& (1 << (g_info.cli.bit_idx)))
			kill(g_info.cli.server_pid, SIGUSR2);
		else
			kill(g_info.cli.server_pid, SIGUSR1);
		++(g_info.cli.bit_idx);
	}
	else if (sig == SIGUSR2 && siginfo->si_pid == g_info.cli.server_pid)
		ft_print_n_exit("Connection Lost . . .", 3);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		ft_print_n_exit("Wrong arguments !", 1);
	ft_print_start_pid(CLIENT);
	ft_set_sigaction(client_handler);
	g_info.cli = (t_client){ft_atoi(*(av + 1)), *(av + 2), 0, 0, 0};
	ft_print_pid_msg(g_info.cli.server_pid, g_info.cli.msg);
	if (kill(g_info.cli.server_pid, SIGUSR1) < 0)
		ft_print_n_exit("Can't connect to server !", 3);
	while (++g_info.cli.counter < TIMEOUT_CNT)
		;
	ft_print_n_exit("Server Timeout !", 4);
}
