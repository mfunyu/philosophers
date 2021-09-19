/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_timestamp_log.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:00:43 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/19 15:37:58 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int64_t	print_timestamp_log(t_info *info, t_action action)
{
	char	*status;
	int64_t	timestamp_in_ms;

	status = "";
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
	pthread_mutex_lock(&info->shared->mutexs[PRINT]);
	timestamp_in_ms = get_timestamp_ms();
	if (timestamp_in_ms == ERROR)
		return (ERROR);
	printf("%"PRId64" %d %s\n", timestamp_in_ms, info->philo_id, status);
	if (action == DIE)
		return (ERROR);
	pthread_mutex_unlock(&info->shared->mutexs[PRINT]);
	return (timestamp_in_ms);
}
