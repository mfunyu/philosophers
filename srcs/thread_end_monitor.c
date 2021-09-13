/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_end_monitor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:43:05 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 16:02:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_end_monitor(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	printf("E \n");
	pthread_mutex_lock(info->shared->mutexs + EOS);
	info->shared->flag_eos = 1;
	pthread_mutex_unlock(info->shared->mutexs + EOS);
	usleep(1000);
	return (NULL);
}

