/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 22:23:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/08/17 23:30:20 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static const char	*_skip_spaces(const char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	return (str);
}

int	ft_atoi_check(const char *n, int *error)
{
	long long	nb;
	int			sign;

	nb = 0;
	sign = 1;
	*error = ERROR;
	n = _skip_spaces(n);
	sign = 1;
	if (*n == '-' || *n == '+')
	{
		sign = 44 - *n;
		n++;
	}
	while ('0' <= *n && *n <= '9')
	{
		*error = 1;
		nb = nb * 10 + (*n++ - '0');
		if (nb * sign < INT_MIN || INT_MAX < nb * sign)
		{
			*error = ERROR;
			return (0);
		}
	}
	if (*error == 1 && *n == '\0')
		*error = SUCCESS;
	return ((int)(nb * sign));
}
