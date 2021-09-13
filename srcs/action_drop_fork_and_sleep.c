/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_drop_fork_and_sleep.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:35:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 16:49:20 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int action_drop_fork_and_sleep(t_info *info)
{
	int		right;
	int		left;

	right = info->philo_id;
	if (info->philo_id == info->shared->nb_philos)
		right = 0;
	left = info->philo_id - 1;
	pthread_mutex_lock(info->shared->mutex_forks + right);
	info->shared->arr_forks[right] = 0;
	pthread_mutex_lock(info->shared->mutex_forks + left);
	info->shared->arr_forks[right] = 0;
	print_timestamp_log(info, SLEEP);
	pthread_mutex_unlock(info->shared->mutex_forks + right);
	pthread_mutex_unlock(info->shared->mutex_forks + left);
	ms_sleep(info->shared->time2sleep);
	return (SUCCESS);
}
