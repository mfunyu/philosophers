/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_think.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:13:09 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 14:59:10 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

int	action_think(t_info *info)
{
	if (print_timestamp_log(info, THINK) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
