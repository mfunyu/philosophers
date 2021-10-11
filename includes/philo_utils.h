/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 21:52:51 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 14:58:25 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_UTILS_H
# define PHILO_UTILS_H

# include <stdbool.h> /* bool */
# include <inttypes.h> /* int64_t */

# define SUCCESS 0
# define ERROR 1
# define ERROR_INT INT_MAX

typedef enum e_hand
{
	RIGTH,
	LEFT
}			t_hand;

typedef enum e_action
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}			t_action;

typedef enum e_th_type
{
	DETACH,
	JOIN
}			t_th_type;

typedef enum e_mutex_type
{
	EOS,
	PRINT,
	FINMEAL,
	PHILOMEAL,
	TOTAL
}			t_mutex_type;

typedef struct s_shared	t_shared;
typedef struct s_info	t_info;

int		threads_start(t_info *info);

bool	is_eos(t_info *info);
int64_t	get_time_in_ms(void);
int64_t	print_timestamp_log(t_info *info, t_action action);
int		msleep(int64_t time_sleep_start, int msec);

void	clean(t_shared *shared);

#endif
