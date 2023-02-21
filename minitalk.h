/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:29:50 by rjeong            #+#    #+#             */
/*   Updated: 2023/01/27 21:47:44 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

# define USLEEP_SEC 40

typedef struct s_server
{
	int				client_pid;
	char			temp;
	unsigned int	bit_idx;
}	t_server;

typedef struct s_client
{
	int				server_pid;
	char			*msg;
	unsigned int	msg_idx;
	unsigned int	bit_idx;
}	t_client;

typedef enum e_program_type {
	SERVER,
	CLIENT
}	t_program_type;

int	ft_atoi(const char *str);

void	ft_set_sigaction(void *handler);
void	ft_print_start_pid(t_program_type program_type);
void	ft_print_pid_msg(int pid, char *msg);
void	ft_print_receiving(int pid);
void	ft_print_n_exit(char *str, int exit_code);

#endif
