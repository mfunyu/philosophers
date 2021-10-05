# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 20:42:31 by mfunyu            #+#    #+#              #
#    Updated: 2021/10/05 22:38:44 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
VPATH	:= ./srcs/
SRCS	:= $(shell find ./srcs -type f -name "*.c" | cut -c 8-100)
#SRCS	:= main.c
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
