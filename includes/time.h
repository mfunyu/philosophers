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

#ifndef TIME_H
# define TIME_H

# include <stdbool.h> /* bool */
# include <inttypes.h> /* int64_t */
# include <stdlib.h> /* EXIT_SUCCESS */

typedef struct s_shared	t_shared;
typedef struct s_info	t_info;
typedef enum e_action	t_action;

int64_t	get_time_in_ms(void);
int64_t	print_timestamp_log(t_info *info, t_action action);
int		msleep(int64_t time_sleep_start, int msec);

#endif
