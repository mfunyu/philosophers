/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp_ms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:05:00 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 16:12:31 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int64_t	get_timestamp_ms(void)
{
	struct timeval	tv;
	int64_t			timestamp_in_ms;

	if (gettimeofday(&tv, NULL))
		return (error_return("gettimeofday failed"));
	timestamp_in_ms = (int64_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000.0);
	return (timestamp_in_ms);
}
