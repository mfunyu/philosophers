/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:42:48 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/25 17:42:48 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

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

#endif
