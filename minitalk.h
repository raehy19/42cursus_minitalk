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
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

#define USLEEP_SEC 500
#define WAIT_CNT 1000
#define TIMEOUT_CNT 10000

typedef enum e_program_type {
	SERVER,
	CLIENT
}	t_program_type;

typedef struct s_server
{
	int				client_pid;
	char			temp;
	unsigned int	bit_i;
	unsigned int	counter;
	int				last_sig;
}	t_server_info;

typedef struct s_client
{
	int				server_pid;
	char			*msg;
	unsigned int	msg_i;
	unsigned int	bit_i;
	unsigned int	counter;
	int				last_sig;
}	t_client_info;

typedef struct s_global
{
	t_server_info	ser;
	t_client_info	cli;
}	t_global_info;

t_global_info	g_info;

void	ft_set_sigaction(void *handler);
void	ft_print_start_pid(t_program_type program_type);
void	ft_print_pid_msg(int pid, char *msg);
void	ft_print_receiving(int pid);
void	ft_print_n_exit(char *str, int exit_code);

#endif
