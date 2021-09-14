/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:04:43 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/14 14:21:13 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	is_eos(t_info *info)
{
	pthread_mutex_lock(&info->shared->mutexs[EOS]);
	if (info->shared->flag_eos == 1)
		return (true);
	pthread_mutex_unlock(&info->shared->mutexs[EOS]);
	return (false);
}
