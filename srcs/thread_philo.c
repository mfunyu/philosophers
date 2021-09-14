/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:42:40 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/14 12:52:00 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	printf("%d: %"PRId64"\n", info->philo_id, get_timestamp_ms());
	pthread_mutex_lock(info->shared->mutexs + LASTMEAL + info->philo_id);
	if (!info->ts_lastmeal)
	{
		info->ts_lastmeal = get_timestamp_ms();
		if (info->philo_id % 2)
			usleep(200);
	}
	pthread_mutex_unlock(info->shared->mutexs + LASTMEAL + info->philo_id);
	while (1)
	{
		if (action(action_take_forks, info))
			return (NULL);
		if (action(action_drop_fork_and_sleep, info))
			return (NULL);
		if (action(action_think, info))
			return (NULL);
	}
	return (NULL);
}

