/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_observer_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:43:05 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/19 15:17:41 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	_is_meal_finished(t_info *info)
{
	pthread_mutex_lock(&info->shared->mutexs[FINMEAL]);
	if (info->shared->done_eating >= info->shared->nb_philos)
	{
		pthread_mutex_lock(&info->shared->mutexs[EOS]);
		info->shared->flag_eos = 1;
		pthread_mutex_unlock(&info->shared->mutexs[EOS]);
		pthread_mutex_unlock(&info->shared->mutexs[FINMEAL]);
		return (true);
	}
	pthread_mutex_unlock(&info->shared->mutexs[FINMEAL]);
	return (false);
}

void	*end_observer_thread(void *arg)
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
