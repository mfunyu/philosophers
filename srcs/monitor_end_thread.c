/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_end_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 00:24:15 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/26 23:11:21 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_end_thread(void *arg)
{
	t_shared	*shared;

	shared = (t_shared *)arg;
	while (!death_detected(shared))
	 ;
	return (NULL);
}
