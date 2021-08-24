/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:52:32 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/24 23:35:52 by mfunyu           ###   ########.fr       */
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

int	create_philo_monitor_thread(pthread_t *threads, t_info *info, t_shared *shared)
{
	void		*func;
	int			i;
	int			j;
	void		*ret_val;

	i = 0;
	while (i < shared->nb_of_philos)
	{
		init_t_info(info + i, i + 1, shared);
		j = 0;
		while (j < 2)
		{
			func = philo_thread;
			if (j == 1)
				func = monitor_thread;
			if (pthread_create(threads + i * 2 + j, NULL, func, info + i))
				return (error_return("thread creation failed"));
			pthread_detach(threads[i * 2 + j]);
			j++;
		}
		i++;
	}
	init_t_info(info + i, i, shared);
	if (pthread_create(threads + i * 2, NULL, monitor_end_thread, info + i))
		return (error_return("thread creation failed"));
	pthread_join(threads[i * 2], &ret_val);
	return (0);
}

int	start_threads(t_shared *shared)
{
	t_info		*info;
	t_info		*infohead;
	pthread_t	*threads;
	pthread_t	*threadshead;

	threads = (pthread_t *)malloc((shared->nb_of_philos * 2 + 1) * sizeof(pthread_t));
	info = (t_info *)malloc((shared->nb_of_philos + 1 + 1) * sizeof(t_info));
	threadshead = threads;
	infohead = info;
	if (create_philo_monitor_thread(threads, info, shared))
		return (ERROR);
	null_free(threadshead);
	null_free(infohead);
	return (0);
}

int	philosophers(int ac, char **av)
{
	t_shared	shared;

	if (parse_args(&shared, ac, av))
		return (ERROR);
	if (init_t_shared(&shared))
		return (ERROR);
	pthread_mutex_init(&(shared.mutex), NULL);
	if (start_threads(&shared))
		return (ERROR);
	pthread_mutex_destroy(&(shared.mutex));
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
