/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:52:32 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/22 14:44:22 by mfunyu           ###   ########.fr       */
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

int	start_threads(t_shared *shared)
{
	t_info		*info;
	pthread_t	*threads;
	int			i;
	int			j;
	void		*ret_val;
	void		**func;
	int			someone_died;

	someone_died = 0;
	threads = (pthread_t *)malloc((shared->nb_of_philos * 2 + 1) * sizeof(pthread_t));
	info = (t_info *)malloc((shared->nb_of_philos + 1 + 1) * sizeof(t_info));
	func = (void **)malloc(2 * sizeof(void *));
	func[0] = philo_thread;
	func[1] = monitor_thread;
	i = 1;
	while (i <= shared->nb_of_philos)
	{
		init_t_info(info + i, i, shared, &someone_died);
		j = 0;
		while (j < 2)
		{
			if (pthread_create(threads + i * 2 + j, NULL, func[j], info + i))
				return (error_return("thread creation failed"));
			pthread_detach(threads[i * 2 + j]);
			j++;
		}
		i++;
	}
	init_t_info(info + i, i, shared, &someone_died);
	if (pthread_create(threads + i * 2, NULL, monitor_end_thread, info + i))
		return (error_return("thread creation failed"));
	pthread_join(threads[i * 2], &ret_val);
	null_free(threads);
	null_free(info);
	return (0);
}

int	philosophers(int ac, char **av)
{
	t_shared	shared;
	if (parse_args(&shared, ac, av))
		return (ERROR);
	if (init_t_shared(&shared))
		return (ERROR);
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
