/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:35:19 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/20 00:48:15 by mfunyu           ###   ########.fr       */
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
		if (*(info->someone_died) == 1)
			return (0);
		if (info->last_meal != 0
			&& now - info->last_meal >= info->data->philo->time_to_die / 1000)
		{
			info->action = Die;
			*(info->someone_died) = 1;
			print_log(info);
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
