/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:06:11 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/25 17:38:22 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# include <stdbool.h>

int		threads_start(t_info *info);

void	*thread_philosopher(void *arg);
void	*thread_monitor(void *arg);
void	*thread_end_observer(void *arg);

bool	is_eos(t_info *info);

#endif
