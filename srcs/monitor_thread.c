/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:35:19 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/01 16:50:51 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death(t_info *info)
{
	struct timeval	tv;
	int64_t			now;

	while (!death_detected(info->shared))
	{
		if (gettimeofday(&tv, NULL))
			return (error_return("gettimeofday failed"));
		now = (int64_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000.0);
		if (info->last_meal != 0
			&& now - info->last_meal >= info->shared->time_to_die / 1000)
		{
			pthread_mutex_lock(&(info->shared->mutex_eat));
			if (!death_detected(info->shared))
			{
				info->shared->someone_died = true;
				print_log(info, DIE);
			}
			pthread_mutex_unlock(&(info->shared->mutex_eat));
			return (0);
		}
	}
	return (0);
}

void	*monitor_thread(void *arg)
{
	t_info		*info;

	info = (t_info *)arg;
	check_death(info);
	return (NULL);
}
