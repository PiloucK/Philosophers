/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:04:02 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/14 18:53:36 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int
	test_overflow(
		int current_value,
		int next_digit,
		int sign )
{
	int		x;

	x = INT_MAX / 10 - current_value;
	if (x != 0)
		return (x < 0);
	if (sign != 1)
		return (-(INT_MIN % 10) < next_digit);
	else
		return (INT_MAX % 10 < next_digit);
}

static int
	is_wspace(
		int c )
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int
	is_digit(
		int c )
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int
	strict_atoi(
		const char *str,
		int *error )
{
	int					i;
	int					sign;
	int					total;

	sign = 1;
	total = 0;
	while (is_wspace(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		sign = -(*str - 44);
		++str;
	}
	i = 0;
	while (is_digit(str[i]))
	{
		*error = test_overflow(total, str[i] - '0', sign);
		if (*error)
			return (*error);
		total *= 10;
		total += str[i++] - '0';
	}
	if (str[i])
		*error = 1;
	return (total * sign);
}
