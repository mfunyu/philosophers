/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 21:52:51 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 16:46:19 by mfunyu           ###   ########.fr       */
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
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	*mutexs;
}			t_shared;

typedef struct s_info
{
	t_shared	*shared;
	int			philo_id;
	int			ts_lastmeal;
}			t_info;

/*
** inits
*/
int	init_t_shared(t_shared **shared, int ac, char **av);
int	init_t_info(t_info **info, t_shared *shared);
int	init_mutexes(t_shared **shared);

int	threads_start(t_info *info);

/*
** threads
*/
void	*thread_philo(void *arg);
void	*thread_monitor(void *arg);
void	*thread_end_monitor(void *arg);

/*
** actions
*/
int	action_take_forks(t_info *info);
int action_drop_fork_and_sleep(t_info *info);


bool	is_eos(t_info *info);
int64_t	get_timestamp_ms(void);
int	print_timestamp_log(t_info *info, t_action action);
void	ms_sleep(int time);

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
int		ft_atoi(const char *n);
int		ft_atoi_check(const char *n, int *error);

#endif
