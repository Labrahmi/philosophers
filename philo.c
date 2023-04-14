/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:29:24 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/14 01:48:44 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char const *argv[])
{
	int			i;
	int			is_dead;
	t_philo		*philos;
	t_data		*data;
	int			done;

	data = (t_data *) malloc(sizeof(t_data));
	philos = (t_philo *) malloc(sizeof(t_philo) * NUM);
	data->forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * NUM);
	data->lock_last = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * NUM);
	init_dead_mutex(data, philos);
	ft_launch_threads(philos);
	// usleep(250);
	done = 1;
	while (done)
	{
		i = 0;
		while (i < NUM && done)
		{
			pthread_mutex_lock(&(data->lock_last[i]));
			if (get_time() - philos[i].last_eat > DIE)
			{
				pthread_mutex_unlock(&(data->lock_last[i]));
				pthread_mutex_lock(&(data->lock_death));
				data->is_dead = 1;
				pthread_mutex_unlock(&(data->lock_death));
				printf("%ld %d died\n", get_time() - data->start, (i + 1));
				done = 0;
			}
			else
				pthread_mutex_unlock(&(data->lock_last[i]));
			i++;
		}
		usleep(100);
	}
	i = 0;
	while (i < NUM)
		pthread_join(philos[i++].pthread, NULL);
	return 0;
}
