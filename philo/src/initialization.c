/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:11:43 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/14 20:59:13 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	philo_shared_init(t_philo_params *philo_params)
{
	int		exit_code;

	philo_params->dead = false;
	exit_code = pthread_mutex_init(&philo_params->dead_mutex, NULL);
	if (exit_code == EXIT_SUCCESS)
	{
		exit_code = pthread_mutex_init(&philo_params->out_mutex, NULL);
		if (exit_code == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
		else
			pthread_mutex_destroy(&philo_params->dead_mutex);
	}
	return (main_errors(SHARED_MUTEX_ERROR));
}

void
	init_next_philo(
		t_philo *philo,
		int *exit_code )
{
	philo->next_philo = malloc(sizeof(*philo));
	if (philo->next_philo != NULL)
	{
		philo->next_philo->params = philo->params;
		philo->next_philo->thread_id = philo->thread_id + 1;
		*exit_code = philos_init(philo->next_philo);
		if (*exit_code != EXIT_SUCCESS)
			pthread_mutex_destroy(&philo->meal_time_mutex);
	}
	else
	{
		*exit_code = PHILOS_INIT_FAIL;
		pthread_mutex_destroy(&philo->meal_time_mutex);
	}
}

int
	philos_init(
		t_philo *philo )
{
	static t_philo	*first_philo = NULL;
	int				exit_code;

	if (first_philo == NULL)
		first_philo = philo;
	exit_code = pthread_mutex_init(&philo->fork_mutex, NULL);
	if (exit_code == EXIT_SUCCESS
		&& philo->params->number_of_philosophers != philo->thread_id)
	{
		exit_code = pthread_mutex_init(&philo->meal_time_mutex, NULL);
		if (exit_code == EXIT_SUCCESS)
			init_next_philo(philo, &exit_code);
		if (exit_code != EXIT_SUCCESS)
			pthread_mutex_destroy(&philo->fork_mutex);
	}
	else if (exit_code == EXIT_SUCCESS)
		philo->next_philo = first_philo;
	if (exit_code != EXIT_SUCCESS)
	{
		main_errors(PHILOS_INIT_FAIL);
		free(philo);
	}
	return (exit_code);
}
