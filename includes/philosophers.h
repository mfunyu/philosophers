/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 21:52:51 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/03 23:03:26 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "debug.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>
# include <inttypes.h>

# define SUCCESS 0
# define ERROR 1

typedef enum e_action
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}			t_action;

typedef struct s_shared
{
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_print;
	bool			someone_died;
	int				*forks;
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
}				t_shared;

typedef struct s_info
{
	int				who;
	int				is_start;
	int64_t			last_meal;
	t_action		action;
	t_shared		*shared;
}				t_info;

/*
** inits
*/
int		init_mutexes(t_shared *shared);
int		init_t_shared(t_shared *shared);
int		init_t_info(t_info **info, t_shared *shared);

void	*philo_thread(void *arg);
void	*monitor_thread(void *arg);
void	*monitor_end_thread(void *arg);

int		take_forks(t_info *info);
int64_t	print_log(t_info *info, t_action action);
bool	death_detected(t_shared *shared);
int		exec_func_in_mutex(t_info *info, int arg, int func(t_info *, int));

/*
** error
*/
int		error_return(char *error_msg);

void	null_free(void *used);

/*
** utils
*/
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi_check(const char *n, int *error);

#endif
