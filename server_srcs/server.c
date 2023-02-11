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

void	ft_init_sigaction(void)
{
	struct sigaction	sigaction;

	(void)sigaction.sa_flags;
	(void)sigaction.sa_mask;
}

int	main(void)
{
	ft_print_start_pid(SERVER);
	while (1)
	{
		pause();
	}
}
