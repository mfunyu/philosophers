# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 20:42:31 by mfunyu            #+#    #+#              #
#    Updated: 2021/08/17 22:52:25 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
VPATH	:= ./srcs/
SRCS	:= $(shell find ./srcs -type f -name "*.c" | cut -c 8-100)
#SRCS	:= main.c
OBJS	:= $(SRCS:%.c=$(VPATH)%.o)

INCLUDES:= -I./includes
DSTRCTR	:= ./tests/destructor.c

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror $(INCLUDES)
GFLAGS	:= $(CFLAGS) -fsanitize=address

.PHONY	: all clean fclean re dbg leak leak_Darwin leak_Linux norm

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

dbg		: $(OBJS)
	$(CC) $(GFLAGS) $(OBJS) -o $(NAME)

leak_Linux	: dbg

leak_Darwin	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(DSTRCTR) -o $(NAME)

leak	: leak_$(shell uname)

norm	:
	./tests/norm.sh
