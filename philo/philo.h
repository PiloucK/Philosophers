/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:05:25 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/14 19:01:47 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>

# define SHIT_HAPPENED "is the problem. Shit happened"
# define PHILO_DIED "died"
# define PHILO_EATS "is eating"
# define PHILO_SLEEPS "is sleeping"
# define PHILO_THINKS "is thinking"
# define PHILO_TAKES_FORK "has taken a fork"

typedef enum e_error_codes
{
	PARAM_ERROR = 1,
	SHARED_MUTEX_ERROR,
	PHILO_THREAD_FAIL,
	LIFELINE_CREATION_FAIL,
	PHILOS_INIT_FAIL,
}				t_error_codes;

typedef struct s_philo_params
{
	int				number_of_philosophers;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		odd_delay;
	int				max_meal_count;
	pthread_mutex_t	out_mutex;
	pthread_mutex_t	dead_mutex;
	bool			dead;
	long long		start_time;
}				t_philo_params;

typedef struct s_philo	t_philo;

typedef struct s_philo
{
	t_philo_params	*params;
	t_philo			*next_philo;
	int				thread_id;
	int				meal_count;
	long long		last_meal_time;
	pthread_mutex_t	fork_mutex;
	pthread_mutex_t	meal_time_mutex;
}				t_philo;

long long
get_time_usec(
	);

int
main_errors(
	unsigned int exit_code );

void
my_usleep(
	long long sleep_start_time,
	long long time_to_wait );

void
*philo_behave(
	void *thread_data );

int
philo_birth(
	t_philo *philo );

int
philo_check(
	int ac,
	t_philo_params *philo_params );

int
philo_in(
	int ac,
	char **av,
	t_philo_params *philo_params );

int
philos_init(
	t_philo *philo );

void
*philo_lifeline(
	void *thread_data );

void
philo_out(
	t_philo *talking_philo,
	char *message );

int
philo_shared_init(
	t_philo_params *philo_params );

int
strict_atoi(
	const char *str,
	int *error );

#endif
