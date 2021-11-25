/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 08:21:19 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/25 17:54:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "enums.h"
#include "exit.h"
#include <stddef.h>
#include <stdlib.h>

static int	_malloc_mutex(pthread_mutex_t **mutex_ptr, int len)
{
	*mutex_ptr = (pthread_mutex_t *)malloc((len + 1) * sizeof(pthread_mutex_t));
	if (!(*mutex_ptr))
		return (error_return("malloc failed"));
	return (SUCCESS);
}

static void	_init_mutex(pthread_mutex_t **mutex_ptr, int len)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = *mutex_ptr;
	i = 0;
	while (i < len)
	{
		pthread_mutex_init(mutex + i, NULL);
		i++;
	}
}

int	init_mutexes(t_shared **shared)
{
	t_shared	*shared_p;

	shared_p = *shared;
	if (_malloc_mutex(&(shared_p->mutex_forks), shared_p->nb_philos))
		return (ERROR);
	_init_mutex(&(shared_p->mutex_forks), shared_p->nb_philos);
	if (_malloc_mutex(&(shared_p->mutexes), TOTAL + shared_p->nb_philos))
		return (ERROR);
	_init_mutex(&(shared_p->mutexes), TOTAL + shared_p->nb_philos);
	return (SUCCESS);
}
