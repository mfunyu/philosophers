/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:42:40 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 16:15:33 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	action(int (*func)(t_info *), t_info *info)
{
	if (is_eos(info))
		return (ERROR);
	if (func(info))
		return (ERROR);
	return (SUCCESS);
}

void	*thread_philo(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	printf("T %d\n", info->philo_id);
	while (1)
	{
		if (action(action_take_forks, info))
			return (NULL);
	}
	return (NULL);
}

