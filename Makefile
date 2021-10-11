# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 20:42:31 by mfunyu            #+#    #+#              #
#    Updated: 2021/10/11 14:45:13 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
VPATH	:= ./srcs/
SRCS	:= main.c \
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

.PHONY	: all clean fclean re dbg leak leak_Darwin leak_Linux norm test help

all	: $(NAME) ## Compile all

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean	: ## Remove object files
	$(RM) $(OBJS)

fclean	: clean ## Remove target files
	$(RM) $(NAME)

re	: fclean all ## Run fclean all

dbg	: $(OBJS) ## Run with -fsanitize=address
	$(CC) $(GFLAGS) $(OBJS) -o $(NAME)

leak_Linux	: dbg

leak_Darwin	: $(OBJS)
ifneq ($(shell echo ${TESTER}), $(shell ls | grep ${TESTER}))
	git clone https://github.com/mfunyu/${TESTER}.git
endif
	$(CC) $(CFLAGS) $(OBJS) $(DSTRCTR) -o $(NAME)

leak	: leak_$(shell uname) ## Run leak check

norm	: ## Run norm check
ifneq ($(shell echo ${TESTER}), $(shell ls | grep ${TESTER}))
	git clone https://github.com/mfunyu/${TESTER}.git
endif
	./${TESTER}/norm.sh

test	: ## Run all test scripts
ifneq ($(shell echo ${TESTER}), $(shell ls | grep ${TESTER}))
	git clone https://github.com/mfunyu/${TESTER}.git
endif
	./${TESTER}/test.sh

help	: ## Display this help screen
	@grep -E '^[a-zA-Z_-]+.*:.*?## .*$$' $(MAKEFILE_LIST) \
	| awk 'BEGIN {FS = "\t:.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'
