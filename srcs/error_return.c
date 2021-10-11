/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 07:57:26 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 13:18:49 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error_return(char *error_msg)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	return (ERROR);
}
