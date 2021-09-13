/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 07:55:28 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/12 14:49:57 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_args(int ac, char **av)
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
		i++;
	}
	if (error)
		return (ERROR);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_shared	shared;

	if (ac < 5 || ac > 6 || check_args(ac, av))
		return (error_return("Invalid Arguments"));
	if (init_t_shared(&shared, ac, av))
		return (ERROR);
	if (init_t_shared(&shared, ac, av))
		return (ERROR);
	printf("s %d\n", shared.arr_forks[1]);
	// inits
	// start_thread;
	return (0);
}
