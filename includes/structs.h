/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:16:21 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/25 17:54:54 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stddef.h>
# include <pthread.h>

typedef struct s_shared
{
	int				*arr_forks;
	int				nb_philos;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				nb_eat;
	int				flag_eos;
	int				done_eating;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	*mutexes;
}			t_shared;

typedef struct s_info
{
	t_shared	*shared;
	int			philo_id;
	int			cnt_meal;
	int64_t		ts_lastmeal;
}			t_info;

#endif
