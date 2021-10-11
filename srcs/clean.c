/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:13:30 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 14:31:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo_struct.h"
#include <stdlib.h>

static void	_null_free(void *used)
{
	free(used);
	used = NULL;
}

void	clean(t_shared *shared)
{
	int		i;

	i = 0;
	while (i < shared->nb_philos)
	{
		pthread_mutex_destroy(shared->mutex_forks);
		i++;
	}
	i = 0;
	while (i < TOTAL + shared->nb_philos)
	{
		pthread_mutex_destroy(shared->mutexes);
		i++;
	}
	_null_free(shared->mutex_forks);
	_null_free(shared->mutexes);
	_null_free(shared->arr_forks);
	_null_free(shared);
}
