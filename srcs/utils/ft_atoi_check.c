/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 22:23:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/11 13:46:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>

static const char	*_skip_spaces(const char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	return (str);
}

int	ft_atoi_check(const char *n, int *is_error)
{
	long long	nb;
	int			sign;

	nb = 0;
	sign = 1;
	*is_error = true;
	n = _skip_spaces(n);
	sign = 1;
	if (*n == '-' || *n == '+')
		sign = 44 - *n++;
	while ('0' <= *n && *n <= '9')
	{
		*is_error = -1;
		nb = nb * 10 + (*n++ - '0');
		if (nb * sign < INT_MIN || INT_MAX < nb * sign)
		{
			*is_error = true;
			return (0);
		}
	}
	if (*is_error == -1 && *n == '\0')
		*is_error = false;
	return ((int)(nb * sign));
}
