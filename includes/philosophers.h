/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 21:52:51 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 14:29:57 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdbool.h> /* bool */
# include <inttypes.h> /* int64_t */

# define SUCCESS 0
# define ERROR 1
# define ERROR_INT INT_MAX

# define RIGHT 0
# define LEFT 1

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

/*
** inits
*/
int		init_t_shared(t_shared **shared, int ac, char **av);
int		init_t_info(t_info **info, t_shared *shared);
int		init_mutexes(t_shared **shared);

int		threads_start(t_info *info);

bool	is_eos(t_info *info);
int64_t	get_time_in_ms(void);
int64_t	print_timestamp_log(t_info *info, t_action action);
int		msleep(int64_t time_sleep_start, int msec);

/*
** error
*/
int		error_return(char *error_msg);

void	clean(t_shared *shared);

#endif
