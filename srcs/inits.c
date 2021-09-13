/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 08:21:19 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 09:32:25 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_t_shared(t_shared *shared, int ac, char **av)
{
	shared->nb_philos = ft_atoi(av[1]);
	shared->time2die = ft_atoi(av[2]);
	shared->time2eat = ft_atoi(av[3]);
	shared->time2sleep = ft_atoi(av[4]);
	shared->nb_eat = -1;
	if (ac == 6)
		shared->nb_eat = ft_atoi(av[5]);
	shared->flag_eop = 0;
	shared->arr_forks = (int *)malloc((shared->nb_philos + 1) * sizeof(int));
	if (!shared->arr_forks)
		return (error_return("malloc failed"));
	memset(shared->arr_forks, 0, shared->nb_philos + 1);
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
