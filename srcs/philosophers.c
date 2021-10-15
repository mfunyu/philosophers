/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 07:55:28 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 09: by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"
#include "utils.h"
#include "inits.h"
#include "error.h"

static int	_check_args(const int ac, const char **av)
{
	int		i;
	int		ret;
	int		error;

	i = 1;
	error = 0;
	while (!error && i < ac)
	{
		ret = ft_atoi_check(av[i], &error);
		if (ret < 0)
			error = ERROR;
		if (i == 1 && ret == 0)
			error = ERROR;
		i++;
	}
	if (error)
		return (ERROR);
	return (SUCCESS);
}

int	philosophers(int ac, char **av)
{
	t_shared	*shared;
	t_info		*info;

	if (ac < 5 || ac > 6 || _check_args(ac, (const char **)av))
		return (error_return("invalid arguments"));
	if (init_t_shared(&shared, ac, av))
		return (ERROR);
	if (init_mutexes(&shared))
		return (ERROR);
	if (init_t_info(&info, shared))
		return (ERROR);
	if (threads_start(info))
		return (ERROR);
	clean(shared);
	free(info);
	return (0);
}
