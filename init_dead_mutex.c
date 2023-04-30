/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dead_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:15:49 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/29 23:46:32 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_dead_mutex(t_data *data, t_philo *philos)
{
	int i;

	i = 0;
	data->is_dead = 0;
	pthread_mutex_init(&(data->lock_death), NULL);
	while (i < data->num_p)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		pthread_mutex_init(&(data->lock_last[i]), NULL);
		philos[i].data = data;
		i++;
	}
	usleep(100);
	data->start = get_time();
}
