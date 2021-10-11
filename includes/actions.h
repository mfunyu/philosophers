/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:51:20 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 14:01:48 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

typedef struct s_info	t_info;

int		action_take_forks_and_eat(t_info *info);
int		action_drop_fork_and_sleep(t_info *info);
int		action_think(t_info *info);

#endif
