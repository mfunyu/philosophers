/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:41:57 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/10 00:03:02 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_thread(void *arg)
{
	t_info	*info;
	int64_t	time_passed;

	info = (t_info *)arg;
	while (1)
	{
		pthread_mutex_lock(&info->shared->mutexes[LASTMEAL]);
		time_passed = get_time_in_ms() - info->ts_lastmeal;
		if (!info->ts_lastmeal)
			time_passed = 0;
		pthread_mutex_unlock(&info->shared->mutexes[LASTMEAL]);
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
