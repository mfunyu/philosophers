/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_take_forks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:15:41 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/14 10:51:01 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_a_fork(t_info *info, int hand)
{
	int		fork_nb;
	bool	got_fork;

	if (hand == RIGHT)
	{
		fork_nb = info->philo_id;
		if (info->philo_id == info->shared->nb_philos)
			fork_nb = 0;
	}
	else
		fork_nb = info->philo_id - 1;
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
	take_a_fork(info, RIGHT);
	take_a_fork(info, LEFT);
	return (SUCCESS);
}
