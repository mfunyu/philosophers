/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_drop_fork_and_sleep.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:35:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 14:59:10 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"
#include "philo_struct.h"

int	action_drop_fork_and_sleep(t_info *info)
{
	int		right;
	int		left;
	int64_t	time_sleep_start;

	right = info->philo_id;
	if (info->philo_id == info->shared->nb_philos)
		right = 0;
	left = info->philo_id - 1;
	time_sleep_start = print_timestamp_log(info, SLEEP);
	if (time_sleep_start == ERROR)
		return (ERROR);
	pthread_mutex_lock(&info->shared->mutex_forks[left]);
	info->shared->arr_forks[left] = 0;
	pthread_mutex_unlock(&info->shared->mutex_forks[left]);
	pthread_mutex_lock(&info->shared->mutex_forks[right]);
	info->shared->arr_forks[right] = 0;
	pthread_mutex_unlock(&info->shared->mutex_forks[right]);
	msleep(time_sleep_start, info->shared->time2sleep);
	return (SUCCESS);
}
