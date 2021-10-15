/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_birth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:33:26 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/14 20:55:02 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int
	thread_creation_errors(
		t_philo *philo,
		int thread_creation_error )
{
	pthread_mutex_lock(&philo->params->dead_mutex);
	philo->params->dead = true;
	pthread_mutex_unlock(&philo->params->dead_mutex);
	return (main_errors(thread_creation_error));
}

static void
	thread_creation(
		t_philo *philo,
		pthread_t *philo_thread,
		pthread_t *philo_lifeline_thread,
		int *exit_code )
{
	philo->last_meal_time = philo->params->start_time;
	*exit_code = pthread_create(
			philo_thread, NULL, philo_behave, (void *)philo);
	if (*exit_code == EXIT_SUCCESS)
	{
		*exit_code = pthread_create(
				philo_lifeline_thread, NULL, philo_lifeline, (void *)philo);
		if (*exit_code == EXIT_SUCCESS)
		{
			if (philo->thread_id != philo->params->number_of_philosophers)
				*exit_code = philo_birth(philo->next_philo);
			pthread_join(*philo_lifeline_thread, NULL);
			if (philo->params->dead == false)
				pthread_join(*philo_thread, NULL);
			else
				pthread_detach(*philo_thread);
		}
		else
			*exit_code = thread_creation_errors(philo, LIFELINE_CREATION_FAIL);
	}
	else
		*exit_code = thread_creation_errors(philo, PHILO_THREAD_FAIL);
}

int
	philo_birth(
		t_philo *philo )
{
	pthread_t		philo_thread;
	pthread_t		philo_lifeline_thread;
	int				exit_code;

	thread_creation(philo, &philo_thread, &philo_lifeline_thread, &exit_code);
	pthread_mutex_destroy(&philo->meal_time_mutex);
	pthread_mutex_destroy(&philo->fork_mutex);
	free(philo);
	return (exit_code);
}
