/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:00:21 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/22 14:52:00 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_fork(t_info *info, int left)
{
	int			hand;
	int64_t		ret_time;

	hand = info->who - left;
	if (!left && info->who == info->shared->nb_of_philos)
		hand = 0;
	if (info->is_start && info->who % 2)
		usleep(200);
	info->action = -1;
	while (info->action != Fork && !*(info->shared->someone_died))
	{
		pthread_mutex_lock(&(info->shared->mutex));
		if (info->shared->forks[hand] == 0)
		{
			info->shared->forks[hand] = info->who;
			info->action = Fork;
			ret_time = print_log(info);
			if (info->is_start)
				info->last_meal = ret_time;
		}
		pthread_mutex_unlock(&(info->shared->mutex));
	}
	info->is_start = 0;
	if (*(info->shared->someone_died))
		return (1);
	return (0);
	// printf("who: %d hand: %d fork: %d\n", info->who, left, info->action);
}

void	drop_fork(t_info *info)
{
	int		right;
	int		left;

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

	info->action = action;
	ret = print_log(info);
	if (action == Eat)
		info->last_meal = ret;
	if (time)
		usleep(time);
}

void	*philo_thread(void *arg)
{
	t_info		*info;

	info = (t_info *)arg;
	while (1 && !*(info->shared->someone_died))
	{
		if (take_fork(info, false))
			return (NULL);
		if (take_fork(info, true))
			return (NULL);
		simple_action(Eat, info->shared->time_to_eat, info);
		drop_fork(info);
		simple_action(Sleep, info->shared->time_to_sleep, info);
		simple_action(Think, 0, info);
	}
	return (NULL);
}
