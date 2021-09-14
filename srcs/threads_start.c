/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:13:50 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/14 12:50:07 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	thread_start(pthread_t *thread, void *(*func)(void *), t_info *info, t_th_type type)
{
	if (pthread_create(thread, NULL, func, info))
		return (error_return("pthread_create failed"));
	if (type == DETACH)
	{
		if (pthread_detach(*thread))
			return (error_return("pthread_detach failed"));
	}
	else
	{
		if (pthread_join(*thread, NULL))
			return (error_return("pthread_join failed"));
	}
	return (SUCCESS);
}

int	threads_start(t_info *info)
{
	pthread_t	threads[info->shared->nb_philos * 2];
	pthread_t	end_monitor_thread;
	int			i;

	i = 0;
	while (i < info->shared->nb_philos)
	{
		if (thread_start(&threads[i * 2], thread_philo, info + i, DETACH))
			return (ERROR);
		if (thread_start(&threads[i * 2 + 1], thread_monitor, info + i, DETACH))
			return (ERROR);
		i++;
	}
	if (thread_start(&end_monitor_thread, thread_end_monitor, info + i, JOIN))
		return (ERROR);
	return (SUCCESS);
}
