/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 00:02:24 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/01 16:31:40 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int64_t	print_log(t_info *info, t_action action)
{
	struct timeval	tv;
	char			*status;
	int64_t			timestamp_in_ms;

	if (death_detected(info->shared) && action != DIE)
		return (0);
	status = NULL;
	if (action == FORK)
		status = "has taken a fork";
	else if (action == EAT)
		status = "is eating";
	else if (action == SLEEP)
		status = "is sleeping";
	else if (action == THINK)
		status = "is thinking";
	else if (action == DIE)
		status = "died";
	if (gettimeofday(&tv, NULL))
		return (error_return("gettimeofday failed"));
	timestamp_in_ms = (int64_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000.0);
	printf("%"PRId64" %d %s\n", timestamp_in_ms, info->who, status);
	return (timestamp_in_ms);
}
