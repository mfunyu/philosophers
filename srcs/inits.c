/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 08:21:19 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 16:02:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_t_shared(t_shared **shared, int ac, char **av)
{
	t_shared	*shared_p;

	*shared = (t_shared *)malloc(sizeof(t_shared));
	if (!*shared)
		return (error_return("malloc failed"));
	shared_p = *shared;
	shared_p->nb_philos = ft_atoi(av[1]);
	shared_p->time2die = ft_atoi(av[2]);
	shared_p->time2eat = ft_atoi(av[3]);
	shared_p->time2sleep = ft_atoi(av[4]);
	shared_p->nb_eat = -1;
	if (ac == 6)
		shared_p->nb_eat = ft_atoi(av[5]);
	shared_p->flag_eos = 0;
	shared_p->arr_forks = (int *)malloc((shared_p->nb_philos + 1) * sizeof(int));
	if (!shared_p->arr_forks)
		return (error_return("malloc failed"));
	memset(shared_p->arr_forks, 0, (shared_p->nb_philos + 1) * sizeof(int));
	return (SUCCESS);
}

int	init_t_info(t_info **info, t_shared *shared)
{
	t_info	*info_p;
	int		i;

	*info = (t_info *)malloc(((shared->nb_philos + 1) + 1) * sizeof(t_info));
	if (!*info)
		return (error_return("malloc failed"));
	info_p = *info;
	i = 0;
	while (i < shared->nb_philos + 1)
	{
		info_p->shared = shared;
		info_p->philo_id = i + 1;
		info_p->ts_lastmeal = 0;
		info_p++;
		i++;
	}
	return (SUCCESS);
}

int	init_mutexes(t_shared **shared)
{
	t_shared	*shared_p;
	int		i;

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
		malloc((TOTAL + 1) * sizeof(pthread_mutex_t));
	i = 0;
	while (i < TOTAL)
	{
		pthread_mutex_init(shared_p->mutexs + i, NULL);
		i++;
	}
	return (SUCCESS);
}
