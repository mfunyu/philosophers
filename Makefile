# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 20:42:31 by mfunyu            #+#    #+#              #
#    Updated: 2021/11/25 18:05:58 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
SRCS	:= philosophers.c \
		get_time_in_ms.c \
		error_return.c \
		is_eos.c \
		print_timestamp_log.c \
		clean.c \
		msleep.c \
		init_t_shared.c \
		init_t_info.c \
		init_mutexes.c \
		threads_start.c \
		thread_philosopher.c \
		thread_monitor.c \
		thread_end_observer.c \
		action_drop_fork_and_sleep.c \
		action_take_forks_and_eat.c \
		action_think.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_strlen.c \
		ft_atoi_check.c \
		ft_atoi.c
VPATH	:= srcs/ srcs/actions srcs/exit srcs/inits srcs/threads srcs/time srcs/utils
OBJ_DIR := ./objs/
OBJS	:= $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))
DEPS	:= $(OBJS:%.o=%.d)

INCLUDES:= -I./includes
TESTER	:= tester_philosophers
DSTRCTR	:= ./${TESTER}/destructor.c

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror $(INCLUDES) -MP -MMD
GFLAGS	:= $(CFLAGS) -fsanitize=address

.PHONY	: all clean fclean re

all	: $(NAME) ## Compile all

-include $(DEPS)

$(NAME)	: $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@- mkdir $@

clean	: ## Remove object files
	$(RM) -R $(OBJ_DIR)

fclean	: clean ## Remove target files
	$(RM) $(NAME)

re	: fclean all ## Run fclean all

# ----------------------------------- test ----------------------------------- #

.PHONY	: norm test leak leak_Darwin leak_Linux help

${TESTER}	:
	git clone https://github.com/mfunyu/${TESTER}.git

norm	: ${TESTER} ## Run norm check
	./${TESTER}/norm.sh

test	: ${TESTER} ## Run all test scripts
	./${TESTER}/test.sh

leak_Linux	:
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o $(NAME)

leak_Darwin	: $(OBJS) ${TESTER}
	$(CC) $(CFLAGS) $(OBJS) $(DSTRCTR) -o $(NAME)

leak	: leak_$(shell uname) ## Run leak check

help	: ## Display this help screen
	@grep -E '^[a-zA-Z_-]+.*:.*?## .*$$' $(MAKEFILE_LIST) \
	| awk 'BEGIN {FS = "\t:.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'
