/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 04:06:37 by mfunyu            #+#    #+#             */
/*   Updated: 2021/09/13 15:39:20 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (write(fd, s, ft_strlen(s)) == -1)
		return ;
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (write(fd, s, ft_strlen(s)) == -1)
		return ;
	if (write(fd, "\n", 1) == -1)
		return ;
}
