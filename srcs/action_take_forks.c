/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_take_forks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:15:41 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/14 13:20:41 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_a_fork(t_info *info, int fork_nb, int hand)
{
	bool	got_fork;

	got_fork = false;
	while (!got_fork)
	{
		pthread_mutex_lock(info->shared->mutex_forks + fork_nb);
		if (info->shared->arr_forks[fork_nb] == 0)
		{
			info->shared->arr_forks[fork_nb] = info->philo_id;
			got_fork = true;
			print_timestamp_log(info, FORK);
		}
		pthread_mutex_unlock(info->shared->mutex_forks + fork_nb);
	}
	if (hand == LEFT)
	{
		print_timestamp_log(info, EAT);
		ms_sleep(info->shared->time2eat);
	}
	return (SUCCESS);
}

int	action_take_forks(t_info *info)
{
	int		right;
	int		left;

	right = info->philo_id;
	if (info->philo_id == info->shared->nb_philos)
		right = 0;
	left = info->philo_id - 1;
	take_a_fork(info, right, RIGHT);
	take_a_fork(info, left, LEFT);
	return (SUCCESS);
}
