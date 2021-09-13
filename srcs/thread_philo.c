/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:42:40 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 16:02:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_a_fork(t_info *info, int hand)
{
	int		fork_nb;

	if (hand == RIGHT)
		fork_nb = info->philo_id - 1;
	else
	{
		fork_nb = info->philo_id;
		if (info->philo_id == info->shared->nb_philos)
			fork_nb = 0;
	}
	pthread_mutex_lock(info->shared->mutex_forks + fork_nb);
	if (info->shared->arr_forks[fork_nb] == 0)
		info->shared->arr_forks[fork_nb] = info->philo_id;
	pthread_mutex_unlock(info->shared->mutex_forks + fork_nb);
	return (SUCCESS);
}

int	action_take_forks(t_info *info)
{
	if (!info->ts_lastmeal && info->philo_id % 2)
		usleep(200);
	take_a_fork(info, RIGHT);
	take_a_fork(info, LEFT);
	return (SUCCESS);
}

int	action(int (*func)(t_info *), t_info *info)
{
	if (is_eos(info))
		return (ERROR);
	if (func(info))
		return (ERROR);
	return (SUCCESS);
}

void	*thread_philo(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	printf("T %d\n", info->philo_id);
	while (1)
	{
		if (action(action_take_forks, info))
			return (NULL);
	}
	return (NULL);
}

