/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_shared.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 08:21:19 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/25 17:54:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "utils.h"
#include "exit.h"
#include <string.h>
#include <stdlib.h>

static int	_init_arr_forks(t_shared **shared)
{
	t_shared	*shared_p;

	shared_p = *shared;
	shared_p->arr_forks = (int *)
		malloc((shared_p->nb_philos + 1) * sizeof(int));
	if (!shared_p->arr_forks)
		return (error_return("malloc failed"));
	memset(shared_p->arr_forks, 0, (shared_p->nb_philos + 1) * sizeof(int));
	return (SUCCESS);
}

int	init_t_shared(t_shared **shared, int ac, char **av)
{
	t_shared	*shared_p;

	*shared = (t_shared *)malloc(sizeof(t_shared));
	if (!*shared)
		return (error_return("malloc failed"));
	shared_p = *shared;
	shared_p->nb_philos = ft_atoi(av[1]);
	shared_p->time2die = ft_atoi(av[2]);
	shared_p->time2eat = ft_atoi(av[3]);
	shared_p->time2sleep = ft_atoi(av[4]);
	shared_p->nb_eat = -1;
	if (ac == 6)
		shared_p->nb_eat = ft_atoi(av[5]);
	shared_p->flag_eos = 0;
	shared_p->done_eating = 0;
	if (_init_arr_forks(shared))
		return (ERROR);
	return (SUCCESS);
}
