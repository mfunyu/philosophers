/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_think.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:13:09 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 17:14:31 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	action_think(t_info *info)
{
	print_timestamp_log(info, THINK);
	return (SUCCESS);
}
