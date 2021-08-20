/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:52:32 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/20 22:45:52 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parse_args(t_shared *shared, int ac, char **av)
{
	int		error;

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
	int		num_forks;

	pthread_mutex_init(&(shared->mutex), NULL);
	num_forks = shared->nb_of_philos;
	shared->forks = (int *)malloc((num_forks + 1) * sizeof(int));
	if (!shared->forks)
		return (error_return("malloc failed"));
	memset(shared->forks, 0, num_forks + 1);
	return (0);
}

void	init_t_info(t_info *info, int who, t_shared *shared, int *someone_died)
{
	info->who = who;
	info->someone_died = someone_died;
	info->is_start = 1;
	info->last_meal = 0;
	info->action = -1;
	info->data = shared;
}

int	philosophers(int ac, char **av)
{
	t_info		*info;
	t_shared	shared;
	pthread_t	*thread;
	pthread_t	*thread2;
	int			someone_died;
	int			i;
	void		*ret_val;

	someone_died = 0;
	if (parse_args(&shared, ac, av))
		return (ERROR);
	if (init_t_shared(&shared))
		return (ERROR);
	thread = (pthread_t *)malloc((shared.nb_of_philos + 1) * sizeof(pthread_t));
	thread2 = (pthread_t *)malloc((shared.nb_of_philos + 1 + 1) * sizeof(pthread_t));
	info = (t_info *)malloc((shared.nb_of_philos + 1 + 1) * sizeof(t_info));
	i = 1;
	while (i <= shared.nb_of_philos)
	{
		init_t_info(info + i, i, &shared, &someone_died);
		if (pthread_create(thread + i, NULL, philo_thread, info + i))
			return (error_return("thread creation failed"));
		if (pthread_create(thread2 + i, NULL, monitor_thread, info + i))
			return (error_return("thread creation failed"));
		pthread_detach(thread[i]);
		pthread_detach(thread2[i]);
		i++;
	}
	init_t_info(info + i, i, &shared, &someone_died);
	if (pthread_create(thread2 + i, NULL, monitor_end_thread, info + i))
		return (error_return("thread creation failed"));
	pthread_join(thread2[i], &ret_val);
	// i = 1;
	// while (i <= philo.nb_of_philos)
	// 	pthread_join(thread2[i++], &ret_val);
	null_free(thread);
	null_free(thread2);
	null_free(info);
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
