/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:52:32 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/28 23:10:26 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parse_args(t_shared *shared, int ac, char **av)
{
	int		error;

	error = 0;
	shared->nb_of_philos = ft_atoi_check(av[1], &error);
	shared->time_to_die = ft_atoi_check(av[2], &error) * 1000;
	shared->time_to_eat = ft_atoi_check(av[3], &error) * 1000;
	shared->time_to_sleep = ft_atoi_check(av[4], &error) * 1000;
	shared->must_eat = -1;
	if (ac == 6)
		shared->must_eat = ft_atoi_check(av[5], &error);
	if (error)
		return (error_return("Invalid argument"));
	return (0);
}

int	init_t_shared(t_shared *shared)
{
	bool	someone_died;

	someone_died = false;
	shared->someone_died = &someone_died;
	shared->forks = (int *)malloc((shared->nb_of_philos + 1) * sizeof(int));
	if (!shared->forks)
		return (error_return("malloc failed"));
	memset(shared->forks, 0, shared->nb_of_philos + 1);
	return (0);
}

void	init_t_info(t_info *info, int who, t_shared *shared)
{
	info->who = who;
	info->is_start = 1;
	info->last_meal = 0;
	info->shared = shared;
}

int	start_threads(pthread_t *threads, t_info *info, t_shared *shared)
{
	int			i;
	pthread_t	end_thread;
	void		*ret_val;

	i = 0;
	while (i < shared->nb_of_philos)
	{
		init_t_info(info, ++i, shared);
		if (pthread_create(threads, NULL, philo_thread, info))
			return (error_return("thread creation failed"));
		pthread_detach(*threads++);
		if (pthread_create(threads, NULL, monitor_thread, info++))
			return (error_return("thread creation failed"));
		pthread_detach(*threads++);
	}
	if (pthread_create(&end_thread, NULL, monitor_end_thread, shared))
		return (error_return("thread creation failed"));
	pthread_join(end_thread, &ret_val);
	return (0);
}

int	init_threads(pthread_t **threads, t_info **info, t_shared *shared)
{
	*threads = (pthread_t *)malloc(
			(shared->nb_of_philos * 2) * sizeof(pthread_t));
	if (!*threads)
	{
		null_free(shared->forks);
		null_free(shared->mutex_forks);
		return (error_return("malloc failed"));
	}
	*info = (t_info *)malloc((shared->nb_of_philos) * sizeof(t_info));
	if (!*info)
	{
		null_free(shared->forks);
		null_free(shared->mutex_forks);
		null_free(*threads);
		return (error_return("malloc failed"));
	}
	return (0);
}

int	philosophers(int ac, char **av)
{
	t_shared	shared;
	t_info		*info;
	pthread_t	*threads;

	if (parse_args(&shared, ac, av))
		return (ERROR);
	if (init_t_shared(&shared))
		return (ERROR);
	if (init_mutexes(&shared))
		return (ERROR);
	if (init_threads(&threads, &info, &shared))
		return (ERROR);
	if (start_threads(threads, info, &shared))
		return (ERROR);
	null_free(shared.forks);
	null_free(shared.mutex_forks);
	null_free(threads);
	null_free(info);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 5 || 6 < ac)
		return (error_return("Invalid argument"));
	if (philosophers(ac, av))
		return (ERROR);
	return (0);
}
