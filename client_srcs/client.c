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

typedef struct s_client
{
	int				server_pid;
	char			*msg;
	unsigned int	msg_idx;
	unsigned int	bit_idx;
}	t_client;

t_client	g_info;

void	client_handler(int sig, siginfo_t *siginfo, ucontext_t *uap)
{
	(void)uap;
	if (sig == SIGUSR1 && siginfo->si_pid == g_info.server_pid)
	{
		if (g_info.bit_idx == 8)
		{
			if ((*(g_info.msg + g_info.msg_idx)) == 0)
			{
				kill(g_info.server_pid, SIGUSR1);
				exit(0);
			}
			++g_info.msg_idx;
			g_info.bit_idx = 0;
		}
		++g_info.bit_idx;
		if ((*(g_info.msg + g_info.msg_idx)) & (1 << (g_info.bit_idx - 1)))
			kill(g_info.server_pid, SIGUSR2);
		else
			kill(g_info.server_pid, SIGUSR1);
	}
	else if (sig == SIGUSR2)
		exit(2);
	else
		ft_printf("\nerror!\nsig : %d\nsi_pid : %d\nsi_code : %d\n", sig, siginfo->si_pid, siginfo->si_code);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		exit(1);
	ft_print_start_pid(CLIENT);
	ft_set_sigaction(client_handler);
	g_info = (t_client){ft_atoi((const char *)*(av + 1)), *(av + 2), 0, 0};
	ft_print_pid_msg(g_info.server_pid, g_info.msg);
	kill(g_info.server_pid, SIGUSR1);
	while (1)
		pause();
}
