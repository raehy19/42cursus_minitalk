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

typedef enum e_program_type {
	SERVER,
	CLIENT
}	t_program_type;

void	ft_print_start_pid(t_program_type program_type);
void	ft_send_pid_msg(int pid, char *msg);


#endif
