/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_end_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 00:24:15 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/20 00:48:40 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_end_thread(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	while (!*(info->someone_died))
	{ ; }
	return (NULL);
}
