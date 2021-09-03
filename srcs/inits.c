/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:52:32 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/03 22:36:58 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_t_info(t_info *info, int who, t_shared *shared)
{
	info->who = who;
	info->is_start = 1;
	info->last_meal = 0;
	info->shared = shared;
}

int	init_t_shared(t_shared *shared)
{
	shared->someone_died = false;
	shared->forks = (int *)malloc((shared->nb_of_philos + 1) * sizeof(int));
	if (!shared->forks)
		return (error_return("malloc failed"));
	memset(shared->forks, 0, shared->nb_of_philos + 1);
	return (0);
}

int	init_mutexes(t_shared *shared)
{
	int		i;

	shared->mutex_forks = (pthread_mutex_t *)malloc(
			(shared->nb_of_philos + 1) * sizeof(pthread_mutex_t));
	if (!shared->mutex_forks)
	{
		null_free(shared->forks);
		return (error_return("malloc failed"));
	}
	i = 0;
	while (i++ < shared->nb_of_philos)
		pthread_mutex_init(shared->mutex_forks + i, NULL);
	pthread_mutex_init(&(shared->mutex_eat), NULL);
	pthread_mutex_init(&(shared->mutex_print), NULL);
	return (0);
}

int	init_threads(t_info **info, t_shared *shared)
{
	*info = (t_info *)malloc((shared->nb_of_philos + 1) * sizeof(t_info));
	if (!*info)
	{
		null_free(shared->forks);
		null_free(shared->mutex_forks);
		return (error_return("malloc failed"));
	}
	return (0);
}
