/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_end_observer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:43:05 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 14:59:10 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"
#include "philo_struct.h"
#include <stddef.h>
#include <unistd.h>

static bool	_is_meal_finished(t_info *info)
{
	pthread_mutex_lock(&info->shared->mutexes[FINMEAL]);
	if (info->shared->done_eating >= info->shared->nb_philos)
	{
		pthread_mutex_lock(&info->shared->mutexes[EOS]);
		info->shared->flag_eos = 1;
		pthread_mutex_unlock(&info->shared->mutexes[EOS]);
		pthread_mutex_unlock(&info->shared->mutexes[FINMEAL]);
		return (true);
	}
	pthread_mutex_unlock(&info->shared->mutexes[FINMEAL]);
	return (false);
}

void	*thread_end_observer(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	while (!is_eos(info))
	{
		if (info->shared->nb_eat >= 0 && _is_meal_finished(info))
			break ;
		usleep(200);
	}
	return (NULL);
}
