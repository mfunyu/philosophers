/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_end_monitor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:43:05 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/14 13:17:07 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_end_monitor(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	while (!is_eos(info))
		usleep(200);
	usleep(1000);
	return (NULL);
}