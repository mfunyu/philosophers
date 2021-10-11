/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:45:32 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/08 21:48:23 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"
#include <unistd.h>

#define MAX_DELAY 10000

int	msleep(int64_t time_sleep_start, int msec)
{
	int64_t		end;
	int64_t		left;

	end = time_sleep_start + msec;
	left = end - get_time_in_ms();
	while (left > MAX_DELAY)
	{
		usleep(left / 2);
		left = end - get_time_in_ms();
	}
	while (left)
	{
		usleep(10);
		left = end - get_time_in_ms();
	}
	return (0);
}
