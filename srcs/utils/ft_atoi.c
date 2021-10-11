/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 22:23:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 13:14:04 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static const char	*_skip_spaces(const char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	return (str);
}

int	ft_atoi(const char *n)
{
	long long	nb;
	int			sign;

	nb = 0;
	sign = 1;
	n = _skip_spaces(n);
	sign = 1;
	if (*n == '-' || *n == '+')
		sign = 44 - *n++;
	while ('0' <= *n && *n <= '9')
	{
		nb = nb * 10 + (*n++ - '0');
		if (nb * sign < INT_MIN || INT_MAX < nb * sign)
			return (0);
	}
	return ((int)(nb * sign));
}
