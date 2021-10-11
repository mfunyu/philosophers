/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:41:57 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 14:37:42 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo_struct.h"
#include <unistd.h>

void	*thread_monitor(void *arg)
{
	t_info	*info;
	int64_t	time_passed;
	int		mutex_id;

	info = (t_info *)arg;
	mutex_id = PHILOMEAL + info->philo_id - 1;
	while (1)
	{
		pthread_mutex_lock(&info->shared->mutexes[mutex_id]);
		time_passed = get_time_in_ms() - info->ts_lastmeal;
		if (!info->ts_lastmeal)
			time_passed = 0;
		pthread_mutex_unlock(&info->shared->mutexes[mutex_id]);
		if (time_passed >= info->shared->time2die)
		{
			print_timestamp_log(info, DIE);
			pthread_mutex_lock(&info->shared->mutexes[EOS]);
			info->shared->flag_eos = 1;
			pthread_mutex_unlock(&info->shared->mutexes[EOS]);
			return (NULL);
		}
		if (info->cnt_meal >= info->shared->nb_eat)
		{
			pthread_mutex_lock(&info->shared->mutexes[FINMEAL]);
			info->shared->done_eating++;
			info->cnt_meal = -1;
			pthread_mutex_unlock(&info->shared->mutexes[FINMEAL]);
		}
		usleep(200);
	}
	return (NULL);
}
