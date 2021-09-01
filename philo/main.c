/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:07:07 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/09/01 15:28:19 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philo.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct  s_philo_params
{
	int     number_of_philosophers;
	int     time_to_die;
	int     time_to_eat;
	int     time_to_sleep;
	int     number_of_times_each_philosopher_must_eat;
}               t_philo_params;

int
test_overflow(
    int current_value
    , int next_digit
    , int sign )
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

int
is_wspace(
    int c )
{
	if (c == ' ' || c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int
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

int
philo_in(
    int ac,
    char **av,
	t_philo_params *philo_params )
{
    int     error;

    error = 0;
    philo_params->number_of_philosophers = strict_atoi(av[1], &error);
    if (error || !av[1][0])
        return (EXIT_FAILURE);
    error = 0;
    philo_params->time_to_die = strict_atoi(av[2], &error);
    if (error || !av[2][0])
        return (EXIT_FAILURE);
    error = 0;
    philo_params->time_to_eat = strict_atoi(av[3], &error);
    if (error || !av[3][0])
        return (EXIT_FAILURE);
    error = 0;
    philo_params->time_to_sleep = strict_atoi(av[4], &error);
    if (error || !av[4][0])
        return (EXIT_FAILURE);
    error = 0;
    if (ac == 6)
        philo_params->number_of_times_each_philosopher_must_eat
            = strict_atoi(av[5], &error);
    if (error || (ac == 6 && !av[5][0]))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

void
print_philo_params(
    t_philo_params *philo_params )
{
    printf("| %10i |\n| %10i |\n| %10i |\n| %10i |\n| %10i |\n"
        , philo_params->number_of_philosophers
        , philo_params->time_to_die
        , philo_params->time_to_eat
        , philo_params->time_to_sleep
        , philo_params->number_of_times_each_philosopher_must_eat);
}

int
philo_check(
    int ac
    , t_philo_params *philo_params )
{
    if (philo_params->number_of_philosophers < 1
        || philo_params->time_to_die < 0
        || philo_params->time_to_eat < 0
        || philo_params->time_to_sleep < 0)
        return (EXIT_FAILURE);
    if (ac == 5)
        philo_params->number_of_times_each_philosopher_must_eat = -1;
    else if (philo_params->number_of_times_each_philosopher_must_eat < 0)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int
error_in_params(
    void )
{
    printf("Error:\nProgram needs 4 to 5 positive integers\n");
    return (EXIT_FAILURE);
}

int
main(
	int ac
	, char **av )
{
	t_philo_params	philo_params;

	if (ac != 5 && ac != 6)
		return (error_in_params());
    if (philo_in(ac, av, &philo_params) == EXIT_FAILURE)
	    return (error_in_params());
    if (philo_check(ac, &philo_params) == EXIT_FAILURE)
        return (error_in_params());
    print_philo_params(&philo_params);
	return (EXIT_SUCCESS);
}
