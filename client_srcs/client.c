/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:38:49 by rjeong            #+#    #+#             */
/*   Updated: 2023/02/08 21:22:58 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	client_handler(int sig, siginfo_t *siginfo, ucontext_t *uap)
{
	(void)uap;
	ft_printf("sig : %d\nsi_pid : %d\n", sig, siginfo->si_pid);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		exit(1);
	ft_print_start_pid(CLIENT);
	ft_set_sigaction(client_handler);
	pid = ft_atoi((const char *)*(av + 1));
	ft_send_pid_msg(pid, *(av + 2));
	// convert av to signal
	// send to server
}
