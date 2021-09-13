/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 07:55:28 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 08:12:15 by mfunyu           ###   ########.fr       */
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
	t_info		*info;

	if (ac < 5 || ac > 6 || check_args(ac, av))
		return (error_return("Invalid Arguments"));
	if (init_t_shared(&shared, ac, av))
		return (ERROR);
	if (init_t_shared(&shared, ac, av))
		return (ERROR);
	if (init_t_info(&info, &shared))
		return (ERROR);
	printf("%d: %d\n", (info + 3)->philo_nb, (info + 3)->shared->arr_forks[1]);
	// start_thread;
	return (0);
}
