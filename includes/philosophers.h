/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 21:52:51 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/02 12:09:54 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>
# include <inttypes.h>

# define SUCCESS 0
# define ERROR 1
# define ERROR_INT INT_MAX

# define RIGHT 0
# define LEFT 1

typedef enum e_action
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}			t_action;

typedef enum e_th_type
{
	DETACH,
	JOIN
}			t_th_type;

typedef enum e_mutex_type
{
	EOS,
	PRINT,
	FINMEAL,
	PHILOMEAL,
	TOTAL
}			t_mutex_type;

typedef struct s_shared
{
	int				*arr_forks;
	int				nb_philos;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				nb_eat;
	int				flag_eos;
	int				done_eating;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	*mutexes;
}			t_shared;

typedef struct s_info
{
	t_shared	*shared;
	int			philo_id;
	int			cnt_meal;
	int64_t		ts_lastmeal;
}			t_info;

/*
** inits
*/
int		init_t_shared(t_shared **shared, int ac, char **av);
int		init_t_info(t_info **info, t_shared *shared);
int		init_mutexes(t_shared **shared);

int		threads_start(t_info *info);

/*
** threads
*/
void	*philosopher_thread(void *arg);
void	*monitor_thread(void *arg);
void	*end_observer_thread(void *arg);

/*
** actions
*/
int		action_take_forks_and_eat(t_info *info);
int		action_drop_fork_and_sleep(t_info *info);
int		action_think(t_info *info);

bool	is_eos(t_info *info);
int64_t	get_timestamp_ms(void);
int64_t	print_timestamp_log(t_info *info, t_action action);
int		ms_sleep(int time);

/*
** error
*/
int		error_return(char *error_msg);

void	clean(t_shared *shared);

/*
** utils
*/
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *n);
int		ft_atoi_check(const char *n, int *error);

#endif
