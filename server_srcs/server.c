/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:38:35 by rjeong            #+#    #+#             */
/*   Updated: 2023/01/27 21:47:37 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ***********************************************	*************************** */

#include "../minitalk.h"
#include "../ft_printf/ft_printf.h"

int	main(void)
{
	ft_printf("Sever Started, SEVER PID : %d", getpid());
//	wait signal
}
