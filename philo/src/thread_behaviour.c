/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_behaviour.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:38:42 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/14 18:59:09 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void
	timestamp_meal_start(
		t_philo *philo )
{
	pthread_mutex_lock(&philo->meal_time_mutex);
	philo->last_meal_time = get_time_usec();
	pthread_mutex_unlock(&philo->meal_time_mutex);
}

void
	deadlock_free_fork_lock(
		t_philo *philo )
{
	if (philo->thread_id != philo->params->number_of_philosophers)
	{
		pthread_mutex_lock(&philo->next_philo->fork_mutex);
		philo_out(philo, PHILO_TAKES_FORK);
		pthread_mutex_lock(&philo->fork_mutex);
	}
	else
	{
		pthread_mutex_lock(&philo->fork_mutex);
		philo_out(philo, PHILO_TAKES_FORK);
		pthread_mutex_lock(&philo->next_philo->fork_mutex);
	}
	philo_out(philo, PHILO_TAKES_FORK);
}

void
	just_eat(
		t_philo *philo )
{
	deadlock_free_fork_lock(philo);
	timestamp_meal_start(philo);
	philo->meal_count++;
	philo_out(philo, PHILO_EATS);
	my_usleep(philo->last_meal_time, philo->params->time_to_eat);
	pthread_mutex_unlock(&philo->fork_mutex);
	pthread_mutex_unlock(&philo->next_philo->fork_mutex);
	philo_out(philo, PHILO_SLEEPS);
	my_usleep(philo->last_meal_time, philo->params->time_to_eat
		+ philo->params->time_to_sleep);
	philo_out(philo, PHILO_THINKS);
	my_usleep(philo->last_meal_time, philo->params->time_to_eat
		* (1 + philo->params->number_of_philosophers % 2)
		+ philo->params->time_to_sleep);
}

void
	philo_try_eat(
		t_philo *philo )
{
	if (philo->meal_count != 0)
		just_eat(philo);
	else
	{
		if (philo->thread_id != philo->params->number_of_philosophers)
			my_usleep(philo->last_meal_time,
				philo->params->odd_delay * (philo->thread_id % 2));
		else
			my_usleep(philo->last_meal_time,
				philo->params->odd_delay * (philo->thread_id % 2) * 2);
		just_eat(philo);
	}
}

void *
	philo_behave(
		void *thread_data )
{
	t_philo		*philo;

	philo = thread_data;
	philo->meal_count = 0;
	while (philo->params->max_meal_count < 0
		|| philo->meal_count
		< philo->params->max_meal_count)
	{
		pthread_mutex_lock(&philo->params->dead_mutex);
		if (philo->params->dead != true)
		{
			pthread_mutex_unlock(&philo->params->dead_mutex);
			philo_try_eat(philo);
		}
		else
		{
			pthread_mutex_unlock(&philo->params->dead_mutex);
			break ;
		}
	}
	return (NULL);
}
