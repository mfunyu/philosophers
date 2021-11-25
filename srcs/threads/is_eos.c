/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:04:43 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/25 17:54:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "enums.h"
#include <pthread.h>
#include <stdbool.h>

bool	is_eos(t_info *info)
{
	pthread_mutex_lock(&info->shared->mutexes[EOS]);
	if (info->shared->flag_eos == 1)
	{
		pthread_mutex_unlock(&info->shared->mutexes[EOS]);
		return (true);
	}
	pthread_mutex_unlock(&info->shared->mutexes[EOS]);
	return (false);
}
