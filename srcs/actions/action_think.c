/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_think.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:13:09 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/25 17:42:07 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"
#include "enums.h"
#include "exit.h"

int	action_think(t_info *info)
{
	if (print_timestamp_log(info, THINK) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
