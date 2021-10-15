/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:58:04 by clkuznie          #+#    #+#             */
/*   Updated: 2021/10/14 19:01:18 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long
	get_time_usec(
		)
{
	struct timeval	timeval_current_time;

	gettimeofday(&timeval_current_time, NULL);
	return (
		timeval_current_time.tv_sec * 1000000
		+ timeval_current_time.tv_usec
	);
}

void
	my_usleep(
		long long sleep_start_time,
		long long time_to_wait )
{
	long long		time;

	if (time_to_wait != 0)
	{
		while (1)
		{
			time = get_time_usec();
			if ((time - sleep_start_time) < time_to_wait)
			{
				usleep(241);
			}
			else
				return ;
		}
	}
}
