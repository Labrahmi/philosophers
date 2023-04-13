/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:29:24 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/13 23:14:43 by ylabrahm         ###   ########.fr       */
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

	done = 1;
	if (ft_allocate_data(&philos, &data))
		return 0;
	init_dead_mutex(data, philos);
	ft_launch_threads(philos);
	usleep(250);
	while (done)
	{
		i = 0;
		while (i < NUM && done)
		{
			pthread_mutex_lock(&(data->lock_last[i]));
			if (get_time() - philos[i].last_eat > DIE)
			{
				pthread_mutex_unlock(&(data->lock_last[i]));
				pthread_mutex_lock(&(philos[i].data->lock_death));
				data->is_dead = 1;
				pthread_mutex_unlock(&(philos[i].data->lock_death));
				printf("%ld %d died\n", get_time() - data->start, (i + 1));
				done = 0;
			}
			else
				pthread_mutex_unlock(&(data->lock_last[i]));
			i++;
		}
		usleep(250);
	}
	i = 0;
	while (i < NUM)
		pthread_join(philos[i++].pthread, NULL);
	return 0;
}
