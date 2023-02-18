/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:38:35 by rjeong            #+#    #+#             */
/*   Updated: 2023/02/08 21:22:53 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	server_handler(int sig, siginfo_t *siginfo, ucontext_t *uap)
{
	(void)uap;
	ft_printf("sig : %d\nsi_pid : %d\n", sig, siginfo->si_pid);
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
