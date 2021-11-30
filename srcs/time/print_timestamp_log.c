/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_timestamp_log.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:00:43 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/25 18:33:11 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "threads.h"
#include "enums.h"
#include "exit.h"
#include "color.h"
#include <stdio.h>
#include <pthread.h>

static char	*_get_color(t_action action)
{
	if (action == DIE)
		return (C_DIE);
	else if (action == FORK)
		return (C_FORK);
	else if (action == EAT)
		return (C_EAT);
	else if (action == SLEEP)
		return (C_SLEEP);
	else if (action == THINK)
		return (C_THINK);
	return (NULL);
}

int64_t	print_timestamp_log(t_info *info, t_action action)
{
	char	*status;
	int64_t	timestamp_in_ms;

	if (is_eos(info))
		return (ERROR);
	else if (action == DIE)
		status = "died";
	else if (action == FORK)
		status = "has taken a fork";
	else if (action == EAT)
		status = "is eating";
	else if (action == SLEEP)
		status = "is sleeping";
	else if (action == THINK)
		status = "is thinking";
	pthread_mutex_lock(&info->shared->mutexes[PRINT]);
	timestamp_in_ms = get_time_in_ms();
	if (timestamp_in_ms == ERROR)
		return (ERROR);
	printf("%s%"PRId64" %d %s%s\n",
		_get_color(action), timestamp_in_ms, info->philo_id, status, C_RESET);
	if (action == DIE)
		return (ERROR);
	pthread_mutex_unlock(&info->shared->mutexes[PRINT]);
	return (timestamp_in_ms);
}
