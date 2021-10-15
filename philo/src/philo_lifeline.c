/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:59:28 by clkuznie          #+#    #+#             */
/*   Updated: 2021/10/14 18:59:41 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *
	philo_lifeline(
		void *thread_data )
{
	t_philo		*philo_to_look_at;

	philo_to_look_at = thread_data;
	while (1)
	{
		pthread_mutex_lock(&philo_to_look_at->meal_time_mutex);
		if (get_time_usec() - philo_to_look_at->last_meal_time
			< philo_to_look_at->params->time_to_die)
		{
			pthread_mutex_unlock(&philo_to_look_at->meal_time_mutex);
			usleep(239);
		}
		else
		{
			pthread_mutex_unlock(&philo_to_look_at->meal_time_mutex);
			if (philo_to_look_at->meal_count
				!= philo_to_look_at->params->max_meal_count)
			{
				philo_out(philo_to_look_at, PHILO_DIED);
				return ((void *)EXIT_FAILURE);
			}
			break ;
		}
	}
	return ((void *)EXIT_SUCCESS);
}
