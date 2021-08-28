/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_func_in_mutex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:00:21 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/28 16:00:17 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	exec_func_in_mutex(t_info *info, int arg, int func(t_info *, int))
{
	int		ret;

	ret = 0;
	if (death_detected(info->shared))
		return (0);
	pthread_mutex_lock(&(info->shared->mutex_forks[arg]));
	ret = (*func)(info, arg);
	pthread_mutex_unlock(&(info->shared->mutex_forks[arg]));
	return (ret);
}
