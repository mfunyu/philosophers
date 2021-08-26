/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_detected.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:00:21 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/26 23:02:54 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	death_detected(t_info *info)
{
	return (*(info->shared->someone_died));
}
