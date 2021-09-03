/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:52:32 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/03 23:03:14 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

int	init_t_info(t_info **info, t_shared *shared)
{
	int		i;

	*info = (t_info *)malloc((shared->nb_of_philos + 2) * sizeof(t_info));
	if (!*info)
	{
		null_free(shared->forks);
		null_free(shared->mutex_forks);
		return (error_return("malloc failed"));
	}
	i = 0;
	while (i < shared->nb_of_philos)
	{
		(*info)[i].who = i + 1;
		(*info)[i].is_start = 1;
		(*info)[i].last_meal = 0;
		(*info)[i].shared = shared;
		i++;
	}
	return (0);
}
