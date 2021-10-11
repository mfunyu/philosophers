/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:07:54 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 13:43:39 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

size_t	ft_strlen(const char *str);

void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

int		ft_atoi(const char *n);
int		ft_atoi_check(const char *n, int *error);

#endif
