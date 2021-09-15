/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:42:40 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/14 14:52:46 by mfunyu           ###   ########.fr       */
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

void	*philosopher_thread(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	pthread_mutex_lock(&info->shared->mutexs[PHILOMEAL + info->philo_id]);
	if (!info->ts_lastmeal && info->philo_id % 2)
		usleep(200);
	pthread_mutex_unlock(&info->shared->mutexs[PHILOMEAL + info->philo_id]);
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
