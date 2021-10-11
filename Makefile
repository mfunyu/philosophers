# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 20:42:31 by mfunyu            #+#    #+#              #
#    Updated: 2021/10/11 15:58:24 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
VPATH	:= ./srcs/
SRCS	:= main.c \
		philosophers.c \
		get_time_in_ms.c \
		error_return.c \
		is_eos.c \
		print_timestamp_log.c \
		clean.c \
		msleep.c \
		inits/init_t_shared.c \
		inits/init_t_info.c \
		inits/init_mutexes.c \
		threads/threads_start.c \
		threads/thread_philosopher.c \
		threads/thread_monitor.c \
		threads/thread_end_observer.c \
		actions/action_drop_fork_and_sleep.c \
		actions/action_take_forks_and_eat.c \
		actions/action_think.c \
		utils/ft_putstr_fd.c \
		utils/ft_putendl_fd.c \
		utils/ft_strlen.c \
		utils/ft_atoi_check.c \
		utils/ft_atoi.c
OBJS	:= $(SRCS:%.c=$(VPATH)%.o)

INCLUDES:= -I./includes
TESTER	:= tester_philosophers
DSTRCTR	:= ./${TESTER}/destructor.c

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror $(INCLUDES)
GFLAGS	:= $(CFLAGS) -fsanitize=address

.PHONY	: all clean fclean re

all	: $(NAME) ## Compile all

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean	: ## Remove object files
	$(RM) $(OBJS)

fclean	: clean ## Remove target files
	$(RM) $(NAME)

re	: fclean all ## Run fclean all


#################################################

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
