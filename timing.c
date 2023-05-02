/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:23:26 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/05/02 01:32:27 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	my_sleep(int ms, t_philo *philo)
{
	struct timeval	tv;
	long			start;
	int				done;

	done = 1;
	gettimeofday(&tv, NULL);
	start = get_time();
	while (done)
	{
		usleep(500);
		if ((get_time() - start) >= ms)
			return ;
		pthread_mutex_lock(&(philo->data->lock_death));
		if (philo->data->is_dead == 1)
			done = 0;
		pthread_mutex_unlock(&(philo->data->lock_death));
	}
}
