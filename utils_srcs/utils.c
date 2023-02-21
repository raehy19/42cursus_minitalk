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
	char	*type;

	if (program_type == SERVER)
		type = "Server";
	else if (program_type == CLIENT)
		type = "Client";
	else
		exit(5);
	ft_printf("\n\033[36;40m%s start . . .\033[0;31m\n%s PID : ", type, type);
	ft_printf("\033[32m%d\033[0m\n", getpid());
}

void	ft_print_pid_msg(int pid, char *msg)
{
	ft_printf("\n\033[33;40mSending message to Server . . .\033[0m\n");
	ft_printf("\033[34mServer PID : \033[35m%d\033[0m\n", pid);
	ft_printf("\033[34mMessage    : \033[35m%s\033[0m\n", msg);
}

void	ft_print_receiving(int pid)
{
	ft_printf("\n\033[33;40mReceiving message from Client . . .\033[0m\n");
	ft_printf("\033[34mClient PID : \033[35m%d\033[0m\n", pid);
	ft_printf("\033[34mMessage    : \033[35m");
}

void	ft_print_n_exit(char *str, int exit_code)
{
	if (exit_code == 0)
		ft_printf("\n\033[36;40m%s\033[0m\n", str);
	else
		ft_printf("\n\033[31;40m%s\033[0m\n", str);
	exit(exit_code);
}
