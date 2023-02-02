# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 14:55:50 by rjeong            #+#    #+#              #
#    Updated: 2023/02/02 15:22:26 by rjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lib_ft_printf.a
LIBFT := libft/libft.a
LIBFT_DIR := libft
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
AR := ar
ARFLAG := -crs

PRINTF_SRCS := \
	ft_printf.c \
	ft_printf_parse_functions.c \
	ft_printf_functions_1.c \
	ft_printf_functions_2.c \
	ft_printf_functions_utils_1.c \
	ft_printf_functions_utils_2.c

PRINTF_OBJS := $(PRINTF_SRCS:.c=.o)

all : $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(PRINTF_OBJS)

fclean : clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re : fclean
	make all

$(LIBFT) :
	make -C $(LIBFT_DIR) all

$(NAME) : $(LIBFT) $(PRINTF_OBJS)
	cp $(LIBFT) ./$(NAME)
	$(AR) $(ARFLAG) $@ $(PRINTF_OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean re

