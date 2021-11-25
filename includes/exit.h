/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:52:49 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/25 17:35:22 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include <stdlib.h>

# define SUCCESS EXIT_SUCCESS
# define ERROR EXIT_FAILURE

typedef struct s_shared	t_shared;

int		error_return(char *error_msg);

void	clean(t_shared *shared);

#endif
