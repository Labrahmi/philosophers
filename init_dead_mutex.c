/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dead_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:15:49 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/12 17:09:02 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_dead_mutex(t_mutex *mutex, t_philo *philos, int *is_dead)
{
	int i;

	i = 0;
	*(is_dead) = 0;
	pthread_mutex_init(&(mutex->death), NULL);
	while (i < NUM)
	{
		philos[i].lock_death = &(mutex->death);
		philos[i].is_dead = is_dead;
		i++;
	}
	usleep(100);
}
