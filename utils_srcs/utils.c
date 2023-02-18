/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:13:30 by rjeong            #+#    #+#             */
/*   Updated: 2023/02/11 17:13:32 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_set_sigaction(void *handler)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_flags = SA_SIGINFO | SA_RESTART;
	act.sa_sigaction = handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

void	ft_print_start_pid(t_program_type program_type)
{
	char	*a;

	if (program_type == SERVER)
		a = "Server";
	else if (program_type == CLIENT)
		a = "Client";
	else
		exit(5);
	ft_printf("\n\033[36;40m%s start . . .\033[0;31m\n%s PID : ",a,a);
	ft_printf("\033[32m%d\033[0m\n", getpid());
}

void	ft_send_pid_msg(int pid, char *msg)
{
	ft_printf("\n\033[33;40mSending message to Server . . .\033[0m\n");
	ft_printf("\033[34mServer PID : \033[35m%d\033[0m\n", pid);
	ft_printf("\033[34mMessage    : \033[35m%s\033[0m\n", msg);
}
