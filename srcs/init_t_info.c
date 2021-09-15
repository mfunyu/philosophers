/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 08:21:19 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/15 16:08:42 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_t_info(t_info **info, t_shared *shared)
{
	t_info	*info_p;
	int		i;

	*info = (t_info *)malloc(((shared->nb_philos + 1) + 1) * sizeof(t_info));
	if (!*info)
		return (error_return("malloc failed"));
	info_p = *info;
	i = 0;
	while (i < shared->nb_philos + 1)
	{
		info_p->shared = shared;
		info_p->philo_id = i + 1;
		info_p->cnt_meal = 0;
		info_p->ts_lastmeal = 0;
		info_p++;
		i++;
	}
	return (SUCCESS);
}
