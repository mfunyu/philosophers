/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:00:21 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/28 14:26:26 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	simple_action(t_action action, int time, t_info *info)
{
	int64_t		ret;

	if (death_detected(info->shared))
		return ;
	ret = print_log(info, action);
	if (action == EAT)
		info->last_meal = ret;
	if (time)
		usleep(time);
}

void	drop_fork_and_sleep(t_info *info)
{
	int		right;
	int		left;

	if (death_detected(info->shared))
		return ;
	right = info->who;
	left = right - 1;
	if (info->who == info->shared->nb_of_philos)
		right = 0;
	pthread_mutex_lock(&(info->shared->mutex));
	info->shared->forks[right] = 0;
	info->shared->forks[left] = 0;
	print_log(info, SLEEP);
	pthread_mutex_unlock(&(info->shared->mutex));
	usleep(info->shared->time_to_sleep);
}

void	*philo_thread(void *arg)
{
	t_info		*info;

	info = (t_info *)arg;
	while (!death_detected(info->shared))
	{
		if (take_forks(info))
			return (NULL);
		simple_action(EAT, info->shared->time_to_eat, info);
		drop_fork_and_sleep(info);
		simple_action(THINK, 0, info);
	}
	return (NULL);
}
