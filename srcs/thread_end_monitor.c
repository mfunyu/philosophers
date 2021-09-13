/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_end_monitor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:43:05 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 09:25:29 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_end_monitor(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	printf("E %d: %d\n", info->philo_id, info->shared->arr_forks[1]);
	return (NULL);
}

