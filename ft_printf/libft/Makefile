# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 14:55:50 by rjeong            #+#    #+#              #
#    Updated: 2023/01/27 22:28:51 by rjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
AR := ar
ARFLAG := crs

LIBFT_SRCS := \
	ft_strlen.c \
	ft_strrev.c \
	ft_long_to_ascii.c \
	ft_unsigned_long_to_ascii.c \
	ft_unsigned_hex_to_ascii.c \
	ft_isdigit.c \
	ft_max.c

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT_OBJS)
	$(AR) $(ARFLAG) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(LIBFT_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re

