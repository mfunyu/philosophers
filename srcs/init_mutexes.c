/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 08:21:19 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/14 17:23:40 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutexes(t_shared **shared)
{
	t_shared	*shared_p;
	int			i;

	shared_p = *shared;
	shared_p->mutex_forks = (pthread_mutex_t *)
		malloc((shared_p->nb_philos + 1) * sizeof(pthread_mutex_t));
	if (!shared_p->mutex_forks)
		return (error_return("malloc failed"));
	i = 0;
	while (i < shared_p->nb_philos)
	{
		pthread_mutex_init(shared_p->mutex_forks + i, NULL);
		i++;
	}
	shared_p->mutexs = (pthread_mutex_t *)
		malloc((TOTAL + shared_p->nb_philos + 1) * sizeof(pthread_mutex_t));
	i = 0;
	while (i < TOTAL + shared_p->nb_philos)
	{
		pthread_mutex_init(shared_p->mutexs + i, NULL);
		i++;
	}
	return (SUCCESS);
}
