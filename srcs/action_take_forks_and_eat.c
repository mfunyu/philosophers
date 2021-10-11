/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_take_forks_and_eat.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:15:41 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 12:11:22 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	_set_ts_and_cnt_meal(t_info *info, int64_t timestamp, bool update)
{
	pthread_mutex_lock(&info->shared->mutexes[LASTMEAL]);
	if (!info->ts_lastmeal || update)
		info->ts_lastmeal = timestamp;
	pthread_mutex_unlock(&info->shared->mutexes[LASTMEAL]);
	if (update && info->cnt_meal >= 0)
		info->cnt_meal++;
}

static int	_take_a_fork(t_info *info, int fork_nb)
{
	bool	got_fork;
	int64_t	timestamp;

	got_fork = false;
	while (!got_fork)
	{
		pthread_mutex_lock(&info->shared->mutex_forks[fork_nb]);
		if (info->shared->arr_forks[fork_nb] == 0)
		{
			info->shared->arr_forks[fork_nb] = info->philo_id;
			got_fork = true;
			timestamp = print_timestamp_log(info, FORK);
			if (timestamp == ERROR)
				return (ERROR);
			_set_ts_and_cnt_meal(info, timestamp, false);
		}
		pthread_mutex_unlock(&info->shared->mutex_forks[fork_nb]);
		if (!got_fork)
			usleep(200);
	}
	return (SUCCESS);
}

int	action_take_forks_and_eat(t_info *info)
{
	int		right;
	int		left;
	int64_t	timestamp;

	right = info->philo_id;
	if (info->philo_id == info->shared->nb_philos)
		right = 0;
	left = info->philo_id - 1;
	if (_take_a_fork(info, right))
		return (ERROR);
	if (_take_a_fork(info, left))
		return (ERROR);
	timestamp = print_timestamp_log(info, EAT);
	if (timestamp == ERROR)
		return (ERROR);
	_set_ts_and_cnt_meal(info, timestamp, true);
	msleep(info->shared->time2eat);
	return (SUCCESS);
}
