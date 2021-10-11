/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:43:55 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 14:44:37 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITS_H
# define INITS_H

typedef struct s_shared	t_shared;
typedef struct s_info	t_info;

int		init_t_shared(t_shared **shared, int ac, char **av);
int		init_t_info(t_info **info, t_shared *shared);
int		init_mutexes(t_shared **shared);

#endif
