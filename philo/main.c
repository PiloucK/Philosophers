/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:07:07 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/08/23 17:42:21 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philo.h"
#include <stdlib.h>
#include <limits.h>

typedef struct  s_philo_params
{
	int     number_of_philosophers;
	int     time_to_die;
	int     time_to_eat;
	int     time_to_sleep;
	int     number_of_times_each_philosopher_must_eat;
}               t_philo_params;

int
	stayinflow(int current, int next_digit, int sign)
{
	int		tmp;

	tmp = INT_MAX / 10 - current;
	if (tmp > 0)
		return (EXIT_SUCCESS);
	if (tmp < 0)
		return (EXIT_FAILURE);
	if (sign != 1)
		return (EXIT_FAILURE * (next_digit > INT_MAX % 10));
	return (EXIT_FAILURE * (-next_digit > INT_MIN % 10));
}

int
	strict_atoi(
	const char *str,
	int *error)
{
	int					i;
	int					sign;
	int					total;

	sign = 1;
	total = 0;
	while (ft_iswspace(*str))
		++str;
	if ((*str == '-' && (sign = -1)) || *str == '+')
		++str;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		if ((*error = (stayinflow(total, str[i] - '0', sign) != 1)))
			return (*error);
		total *= 10;
		total += str[i] - '0';
		i++;
	}
	if (str[i])
		*error = 1;
	return (total * sign);
}

void
philo_in(
	t_philo_params philo_params)
{
	;
}

int
main(
	int ac
	, char **av)
{
	t_philo_params	philo_params;

	if (ac != 4 && ac != 5)
		return (EXIT_FAILURE);
	philo_in(philo_params);
	return (EXIT_SUCCESS);
}
