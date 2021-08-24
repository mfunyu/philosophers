/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:35:19 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/23 01:55:54 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death(t_info *info)
{
	struct timeval	tv;
	int64_t			now;

	while (1)
	{
		if (gettimeofday(&tv, NULL))
			return (error_return("gettimeofday failed"));
		now = (int64_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000.0);
		if (*(info->shared->someone_died))
			return (0);
		if (info->last_meal != 0
			&& now - info->last_meal >= info->shared->time_to_die / 1000)
		{
			// if (!*(info->shared->someone_died))
			// {
				pthread_mutex_lock(&(info->shared->mutex));
				*(info->shared->someone_died) = true;
				print_log(info, DIE);
				pthread_mutex_unlock(&(info->shared->mutex));
			// }
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
