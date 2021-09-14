/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:41:57 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/14 10:33:17 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_monitor(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	while (1)
	{
		pthread_mutex_lock(info->shared->mutexs + LASTMEAL + info->philo_id);
		if (info->ts_lastmeal
			&& get_timestamp_ms() - info->ts_lastmeal >= info->shared->time2die)
		{
			// printf("diff %ld\n", get_timestamp_ms() - info->ts_lastmeal);
			pthread_mutex_lock(info->shared->mutexs + EOS);
			info->shared->flag_eos = 1;
			print_timestamp_log(info, DIE);
			pthread_mutex_unlock(info->shared->mutexs + EOS);
			return (NULL);
		}
		pthread_mutex_unlock(info->shared->mutexs + LASTMEAL + info->philo_id);
	}
	return (NULL);
}

