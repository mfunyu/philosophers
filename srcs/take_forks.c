/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:00:21 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/26 23:06:47 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_a_fork(t_info *info, int hand)
{
	int64_t		timestamp;

	if (death_detected(info))
		return (0);
	if (info->shared->forks[hand] == 0)
	{
		info->shared->forks[hand] = info->who;
		timestamp = print_log(info, FORK);
		if (info->is_start)
			info->last_meal = timestamp;
	}
	return (0);
}

int	wait_a_fork(t_info *info, int hand)
{
	bool	got_a_fork;

	got_a_fork = false;
	while (!death_detected(info) && !got_a_fork)
	{
		got_a_fork = exec_func_in_mutex(info, hand, take_a_fork);
	}
	return (0);
}

int	take_left_fork(t_info *info)
{
	int		left_hand;

	left_hand = info->who - 1;
	if (info->who == info->shared->nb_of_philos)
		left_hand = 0;
	wait_a_fork(info, left_hand);
	return (0);
}

int	take_right_fork(t_info *info)
{
	int		right_hand;

	right_hand = info->who;
	wait_a_fork(info, right_hand);
	return (0);
}

int	take_forks(t_info *info)
{
	if (info->is_start && info->who % 2)
		usleep(200);
	if (take_right_fork(info))
		return (1);
	if (take_left_fork(info))
		return (1);
	info->is_start = 0;
	return (0);
}
