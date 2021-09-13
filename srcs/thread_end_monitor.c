/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_end_monitor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:43:05 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 15:51:30 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_end_monitor(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	printf("E \n");
	pthread_mutex_lock(info->shared->mutexs + EOP);
	info->shared->flag_eop = 1;
	pthread_mutex_unlock(info->shared->mutexs + EOP);
	usleep(1000);
	return (NULL);
}

