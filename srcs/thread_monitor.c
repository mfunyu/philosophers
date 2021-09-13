/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:41:57 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 15:14:58 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_monitor(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	printf("M \n" );
	(void)info;
	return (NULL);
}

