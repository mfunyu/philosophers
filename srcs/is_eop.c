/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:04:43 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 15:51:00 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	is_eop(t_info *info)
{
	pthread_mutex_lock(info->shared->mutexs + EOP);
	if (info->shared->flag_eop == 1)
	{
		printf("eop!\n");
		return (true);
	}
	pthread_mutex_unlock(info->shared->mutexs + EOP);
	return (false);
}
