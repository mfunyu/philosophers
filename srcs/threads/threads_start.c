/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:13:50 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 14:59:10 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"
#include "philo_struct.h"
#include "threads.h"
#include "exit.h"
#include <pthread.h>

static int	_thread_start(void *(*func)(void *), t_info *info, t_th_type type)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, func, info))
		return (error_return("pthread_create failed"));
	if (type == DETACH)
	{
		if (pthread_detach(thread))
			return (error_return("pthread_detach failed"));
	}
	else if (type == JOIN)
	{
		if (pthread_join(thread, NULL))
			return (error_return("pthread_join failed"));
	}
	return (SUCCESS);
}

int	threads_start(t_info *info)
{
	int			i;

	i = 0;
	while (i < info->shared->nb_philos)
	{
		if (_thread_start(thread_philosopher, info + i, DETACH))
			return (ERROR);
		if (_thread_start(thread_monitor, info + i, DETACH))
			return (ERROR);
		i++;
	}
	if (_thread_start(thread_end_observer, info + i, JOIN))
		return (ERROR);
	return (SUCCESS);
}
