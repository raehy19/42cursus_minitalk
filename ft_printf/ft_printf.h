/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:23:13 by rjeong            #+#    #+#             */
/*   Updated: 2023/01/27 21:47:17 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "stdlib.h"
# include "unistd.h"
# include "libft/libft.h"

typedef struct s_flag
{
	int	type;
	int	min_width;
	int	precision;
	int	display_sign;
	int	align_left;
	int	fill_zero;
	int	display_zero_x;
}	t_flag;

int		ft_printf(const char *input, ...);

void	ft_check_type(t_flag *flag, char c);
void	ft_check_precision(t_flag *flag, const char *input, int *i);
void	ft_check_min_width(t_flag *flag, const char *input, int *i);

int		ft_free_n_return(void *p, int value);
int		ft_print_space(int is_zero, int count);
int		ft_print_unsigned(char *str, int len, t_flag *flag);
int		ft_print_pointer(char *str, int len, t_flag *flag, char *zero_x);

int		ft_print_precision_zero(t_flag *flag);
int		ft_print_num_minus(char *str, int len, t_flag *flag);
int		ft_print_num_plus(char *str, int len, t_flag *flag);

int		ft_type_percent(t_flag *flag);
int		ft_type_character(va_list ap, t_flag *flag);
int		ft_type_string(va_list ap, t_flag *flag);
int		ft_type_int(va_list ap, t_flag *flag);

int		ft_type_unsigned_int(va_list ap, t_flag *flag);
int		ft_type_hex_lower(va_list ap, t_flag *flag);
int		ft_type_hex_upper(va_list ap, t_flag *flag);
int		ft_type_pointer(va_list ap, t_flag *flag);

#endif
