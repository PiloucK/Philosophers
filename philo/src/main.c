/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:07:07 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/07 17:42:01 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	main_errors(
		unsigned int exit_code)
{
	if (exit_code == PARAM_ERROR)
		printf("Error:\nProgram needs 4 to 5 positive integers\n");
	else if (exit_code == SHARED_MUTEX_ERROR)
		printf("Error\nOne of shared mutex failed to initialize\n");
	else if (exit_code == PHILO_THREAD_FAIL)
		printf("Error:\nPhilo thread creation failed\n");
	else if (exit_code == LIFELINE_CREATION_FAIL)
		printf("Error:\nLifeline thread creation failed\n");
	else if (exit_code == PHILOS_INIT_FAIL)
		printf("Error:\nOne of individual philos failed to initialize\n");
	return (EXIT_FAILURE);
}

int
	philo_run(
		t_philo_params *philo_params)
{
	t_philo			*first_philo;

	first_philo = malloc(sizeof(*first_philo));
	if (first_philo != NULL)
	{
		first_philo->params = philo_params;
		first_philo->thread_id = 1;
		if (philos_init(first_philo) == EXIT_SUCCESS)
		{
			philo_params->start_time = get_time_usec();
			return (philo_birth(first_philo));
		}
	}
	else
		main_errors(PHILOS_INIT_FAIL);
	return (EXIT_FAILURE);
}

int
	main(
		int ac,
		char **av)
{
	t_philo_params	philo_params;
	int				exit_code;

	if (ac != 5 && ac != 6)
		return (main_errors(PARAM_ERROR));
	if (philo_in(ac, av, &philo_params) != EXIT_SUCCESS)
		return (main_errors(PARAM_ERROR));
	if (philo_check(ac, &philo_params) != EXIT_SUCCESS)
		return (main_errors(PARAM_ERROR));
	if (philo_shared_init(&philo_params) != EXIT_FAILURE)
		exit_code = philo_run(&philo_params);
	else
		return (EXIT_FAILURE);
	pthread_mutex_destroy(&philo_params.dead_mutex);
	pthread_mutex_destroy(&philo_params.out_mutex);
	return (exit_code);
}
