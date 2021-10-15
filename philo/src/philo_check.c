/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:08:36 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/14 18:54:32 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	philo_check(
		int ac,
		t_philo_params *philo_params )
{
	if (philo_params->number_of_philosophers < 1
		|| philo_params->time_to_die < 0
		|| philo_params->time_to_eat < 0
		|| philo_params->time_to_sleep < 0)
		return (EXIT_FAILURE);
	philo_params->odd_delay = philo_params->time_to_eat;
	if (ac == 5)
		philo_params->max_meal_count = -1;
	else if (philo_params->max_meal_count < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
