/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 21:52:51 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/12 14:47:11 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>
# include <inttypes.h>

# define SUCCESS 0
# define ERROR 1

typedef enum e_action
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}			t_action;

typedef struct s_shared
{
	int		*arr_forks;
	int		nb_philos;
	int		time2die;
	int		time2eat;
	int		time2sleep;
	int		nb_eat;
	int		flag_eop;
}			t_shared;

/*
** inits
*/
int	init_t_shared(t_shared *shared, int ac, char **av);

/*
** error
*/
int		error_return(char *error_msg);

void	null_free(void *used);

/*
** utils
*/
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *n);
int		ft_atoi_check(const char *n, int *error);

#endif
