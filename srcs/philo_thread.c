/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:00:21 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/24 23:51:32 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_fork(t_info *info, int hand)
{
	int64_t		ret_time;
	t_action	action;

	action = -1;
	if (*(info->shared->someone_died))
		return (0);
	if (info->is_start && info->who % 2)
		usleep(200);
	while (action != FORK && !*(info->shared->someone_died))
	{
		pthread_mutex_lock(&(info->shared->mutex));
		if (info->shared->forks[hand] == 0 && !*(info->shared->someone_died))
		{
			info->shared->forks[hand] = info->who;
			action = FORK;
			ret_time = print_log(info, FORK);
			if (info->is_start)
				info->last_meal = ret_time;
		}
		pthread_mutex_unlock(&(info->shared->mutex));
	}
	info->is_start = 0;
	if (*(info->shared->someone_died))
		return (1);
	return (0);
}

int	take_right_fork(t_info *info)
{
	int		right_hand;

	right_hand = info->who;
	take_fork(info, right_hand);
	return (0);
}

int	take_left_fork(t_info *info)
{
	int		left_hand;

	left_hand = info->who - 1;
	if (info->who == info->shared->nb_of_philos)
		left_hand = 0;
	take_fork(info, left_hand);
	return (0);
}

void	drop_fork(t_info *info)
{
	int		right;
	int		left;

	if (*(info->shared->someone_died))
		return ;
	right = info->who;
	left = right - 1;
	if (info->who == info->shared->nb_of_philos)
		right = 0;
	pthread_mutex_lock(&(info->shared->mutex));
	info->shared->forks[right] = 0;
	info->shared->forks[left] = 0;
	pthread_mutex_unlock(&(info->shared->mutex));
}

void	simple_action(t_action action, int time, t_info *info)
{
	int64_t		ret;

	if (*(info->shared->someone_died))
		return ;
	ret = print_log(info, action);
	if (action == EAT)
		info->last_meal = ret;
	if (time)
		usleep(time);
}

void	*philo_thread(void *arg)
{
	t_info		*info;

	info = (t_info *)arg;
	while (!*(info->shared->someone_died))
	{
		if (take_right_fork(info))
			return (NULL);
		if (take_left_fork(info))
			return (NULL);
		simple_action(EAT, info->shared->time_to_eat, info);
		drop_fork(info);
		simple_action(SLEEP, info->shared->time_to_sleep, info);
		simple_action(THINK, 0, info);
	}
	return (NULL);
}
