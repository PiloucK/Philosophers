/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:41:48 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/14 18:54:15 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	philo_in(
		int ac,
		char **av,
		t_philo_params *philo_params )
{
	int		error;

	error = 0;
	philo_params->number_of_philosophers = strict_atoi(av[1], &error);
	if (error || !av[1][0])
		return (EXIT_FAILURE);
	error = 0;
	philo_params->time_to_die = (long long)strict_atoi(av[2], &error) * 1000;
	if (error || !av[2][0])
		return (EXIT_FAILURE);
	error = 0;
	philo_params->time_to_eat = (long long)strict_atoi(av[3], &error) * 1000;
	if (error || !av[3][0])
		return (EXIT_FAILURE);
	error = 0;
	philo_params->time_to_sleep = (long long)strict_atoi(av[4], &error) * 1000;
	if (error || !av[4][0])
		return (EXIT_FAILURE);
	error = 0;
	if (ac == 6)
		philo_params->max_meal_count
			= strict_atoi(av[5], &error);
	if (error || (ac == 6 && !av[5][0]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
