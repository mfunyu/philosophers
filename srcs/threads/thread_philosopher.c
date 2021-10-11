/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:55:20 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 14:37:18 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"
#include "actions.h"
#include <unistd.h>

void	*thread_philosopher(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	if (!info->ts_lastmeal && info->philo_id % 2)
		usleep(200);
	while (1)
	{
		if (action_take_forks_and_eat(info))
			return (NULL);
		if (action_drop_fork_and_sleep(info))
			return (NULL);
		if (action_think(info))
			return (NULL);
	}
	return (NULL);
}
