/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:45:32 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/28 00:52:02 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int64_t	_check_usleep_delay(void)
{
	int64_t			expectedtime;
	int64_t			actualtime;

	expectedtime = get_timestamp_ms() + 100;
	if (expectedtime == ERROR)
		return (ERROR_INT);
	usleep(100 * 1000);
	actualtime = get_timestamp_ms();
	if (actualtime == ERROR)
		return (ERROR_INT);
	return (actualtime - expectedtime);
}

static double	_calc_usleep_delay(void)
{
	int64_t	diff;
	double	sum;
	int		i;

	i = 0;
	sum = 0;
	while (i < 10)
	{
		diff = _check_usleep_delay();
		if (diff == ERROR_INT)
			return (ERROR_INT);
		sum += diff;
		i++;
	}
	return (sum / 10);
}

int	ms_sleep(int time)
{
	static int	modifier;

	if (time == -1)
	{
		if (modifier != 0)
			return (ERROR);
		modifier = _calc_usleep_delay() * 1000;
		if (modifier == ERROR_INT)
			return (ERROR);
		printf("modifier_value: %d\n", modifier);
		return (SUCCESS);
	}
	usleep(time * 1000 - modifier);
	return (0);
}

int	set_ms_sleep(void)
{
	return (ms_sleep(-1));
}
