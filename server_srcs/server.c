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
	unsigned char	temp;
	unsigned int	bit_idx;
}	t_server;

static void	server_handler(int sig, siginfo_t *siginfo, ucontext_t *uap)
{
	static t_server	info = {-1, 0, 1};

	(void)uap;
	ft_printf("sig : %d\nsi_pid : %d\n", sig, siginfo->si_pid);
	if (info.client_pid == -1)
	{
		info.client_pid = siginfo->si_pid;
		// print reciving msg
	}
	if (siginfo->si_pid != info.client_pid )
		kill(siginfo->si_pid, SIGUSR2);
	else
	{
		if (info.bit_idx == 8)
		{
			if (info.temp)
			{
				write(1, &info.temp, 1);
				info.temp = 0;
			}
			else
			{
				info.client_pid = -1;
				// recive success msg print
			}
			info.bit_idx = 0;
		}
		else
		{
			if (sig == SIGUSR2)
				info.temp |= (1 << info.bit_idx);
			++info.bit_idx;
		}
		// get bit while 8bit
		// check char is null
		// write
		// clear char
		;
	}
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
