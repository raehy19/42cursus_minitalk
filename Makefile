# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 09:37:01 by rjeong            #+#    #+#              #
#    Updated: 2023/02/08 21:22:19 by rjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := server client
NAME_BONUS := server_bonus client_bonus
FT_PRINTF := ./ft_printf/lib_ft_printf.a
FT_PRINTF_DIR := ft_printf
NAME_S := server
NAME_C := client
NAME_S_BONUS := server_bonus
NAME_C_BONUS := client_bonus
CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
RM := rm -f

SERVER_SRCS := \
	server.c

SERVER_SRCS_BONUS := \
	server_bonus.c

CLIENT_SRCS := \
	client.c

CLIENT_SRCS_BONUS := \
	client_bonus.c

all : $(NAME)

bonus : $(NAME_BONUS)

both :
	make all

SERVER_OBJS := $(addprefix server_srcs/, $(SERVER_SRCS:.c=.o))

SERVER_OBJS_BONUS := $(addprefix server_srcs/, $(SERVER_SRCS_BONUS:.c=.o))

SERVER_DEPS := $(addprefix server_srcs/, $(SERVER_SRCS:.c=.d))

SERVER_DEPS_BONUS := $(addprefix server_srcs/, $(SERVER_SRCS_BONUS:.c=.d))

CLIENT_OBJS := $(addprefix client_srcs/, $(CLIENT_SRCS:.c=.o))

CLIENT_OBJS_BONUS := $(addprefix client_srcs/, $(CLIENT_SRCS_BONUS:.c=.o))

CLIENT_DEPS := $(addprefix client_srcs/, $(CLIENT_SRCS:.c=.d))

CLIENT_DEPS_BONUS := $(addprefix client_srcs/, $(CLIENT_SRCS_BONUS:.c=.d))

-include $(SERVER_DEPS) $(SERVER_DEPS_BONUS) $(CLIENT_DEPS) $(CLIENT_DEPS_BONUS)

clean :
	make -C $(FT_PRINTF_DIR) clean
	$(RM) $(SERVER_OBJS)
	$(RM) $(SERVER_OBJS_BONUS)
	$(RM) $(SERVER_DEPS)
	$(RM) $(SERVER_DEPS_BONUS)
	$(RM) $(CLIENT_OBJS)
	$(RM) $(CLIENT_OBJS_BONUS)
	$(RM) $(CLIENT_DEPS)
	$(RM) $(CLIENT_DEPS_BONUS)

fclean : clean
	make -C $(FT_PRINTF_DIR) fclean
	$(RM) $(BONUS_NAME)
	$(RM) $(NAME)

re : fclean
	make all

$(FT_PRINTF) :
	make -C $(FT_PRINTF_DIR) all

$(NAME_S) : $(FT_PRINTF) $(SERVER_OBJS)
	$(CC) -L$(FT_PRINTF_DIR) $^ -o $@

$(NAME_S_BONUS) : $(SERVER_OBJS_BONUS)
	$(CC) $^ -o $@
	cp $(NAME_S_BONUS) ./$(NAME_S)

$(NAME_C) : $(CLIENT_OBJS)
	$(CC) $^ -o $@

$(NAME_C_BONUS) : $(CLIENT_OBJS_BONUS)
	$(CC) $^ -o $@
	cp $(NAME_C_BONUS) ./$(NAME_C)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all bonus both clean fclean re
