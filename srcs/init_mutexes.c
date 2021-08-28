/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:52:32 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/28 23:08:25 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
