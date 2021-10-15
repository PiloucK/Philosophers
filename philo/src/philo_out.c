/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:40:27 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/14 18:56:28 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int
// 	put_time_in_buf(
// 		char *buf,
// 		long long time,
// 		int i )
// {
// 	if (time / 10 > 0)
// 	{
// 		i = put_time_in_buf(buf, time / 10, i);
// 		buf[i] = time % 10 + '0';
// 		++i;
// 	}
// 	else
// 	{
// 		buf[i] = time % 10 + '0';
// 		++i;
// 	}
// 	return (i);
// }

// void
// 	dirty_unsecured_fast_bzero(
// 		char *buf)
// {
// 	unsigned long	*tmp_buf;

// 	tmp_buf = (unsigned long *)buf;
// 	tmp_buf[0] = 0;
// 	tmp_buf[1] = 0;
// 	tmp_buf[2] = 0;
// 	tmp_buf[3] = 0;
// 	tmp_buf[4] = 0;
// 	tmp_buf[5] = 0;
// 	tmp_buf[6] = 0;
// 	tmp_buf[7] = 0;
// }

void
	philo_out(
		t_philo *talking_philo,
		char *message )
{
	pthread_mutex_lock(&talking_philo->params->out_mutex);
	pthread_mutex_lock(&talking_philo->params->dead_mutex);
	if (talking_philo->params->dead != true)
	{
		pthread_mutex_unlock(&talking_philo->params->dead_mutex);
		if (*message == 'd')
			talking_philo->params->dead = true;
		printf("%lli %d %s\n",
			(get_time_usec() - talking_philo->params->start_time) / 1000,
			talking_philo->thread_id,
			message);
	}
	else
		pthread_mutex_unlock(&talking_philo->params->dead_mutex);
	pthread_mutex_unlock(&talking_philo->params->out_mutex);
}
