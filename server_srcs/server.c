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
#include "stdio.h"

typedef struct s_server
{
	int				client_pid;
	char			temp;
	unsigned int	bit_idx;
}	t_server;

static void	server_handler(int sig, siginfo_t *siginfo, ucontext_t *uap)
{
	static t_server	info = {-1, 0, 0};

//	ft_printf("\nsig in : %d\n",sig);
	(void)uap;
	if (sig == SIGUSR1 && info.client_pid == -1)
	{
		info.client_pid = siginfo->si_pid;
		ft_print_receiving(siginfo->si_pid);
		kill(info.client_pid, SIGUSR1);
	}
	else if (siginfo->si_pid != info.client_pid)
		return;
	else
	{
		if (info.bit_idx == 8)
		{
//	ft_printf("\nsig pid : %d | cli pid : %d\n",siginfo->si_pid, info.client_pid);
//			ft_printf("%c", info.temp);
			info.bit_idx = 0;
			if (info.temp)
			{
				write(1, &info.temp, 1);
//				ft_printf("\n1bit write\n");
				info.temp = '\0';
			}
			else
			{
				info.client_pid = -1;
				ft_printf("\n\033[36;40mReceive Success !\033[0m\n");
				kill(siginfo->si_pid, SIGUSR1);
				return;
			}
		}
		if (sig == SIGUSR2)
			info.temp |= (1 << (info.bit_idx));
		++(info.bit_idx);
//		ft_printf("\nres to cli\n");
		kill(siginfo->si_pid, SIGUSR1);
	}
//	ft_printf("sig : %d\nsi_pid : %d\n", sig, siginfo->si_pid);
}

int	main(void)
{
	ft_print_start_pid(SERVER);
	ft_set_sigaction(server_handler);
	while (1)
	{
		pause();
	}
}
