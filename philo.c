/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:29:24 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/29 23:45:29 by ylabrahm         ###   ########.fr       */
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
	if (!(ft_check_args(argc, argv, data)))
		return (0);
	philos = (t_philo *) malloc(sizeof(t_philo) * data->num_p);
	data->forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * data->num_p);
	data->lock_last = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * data->num_p);
	init_dead_mutex(data, philos);
	ft_launch_threads(philos);
	done = 1;
	while (done)
	{
		i = 0;
		while ((i < data->num_p) && done)
		{
			pthread_mutex_lock(&(data->lock_last[i]));
			if (get_time() - philos[i].last_eat > data->die)
			{
				pthread_mutex_unlock(&(data->lock_last[i]));
				pthread_mutex_lock(&(data->lock_death));
				data->is_dead = 1;
				printf("%ld %d died\n", get_time() - data->start, (i + 1));
				done = 0;
				pthread_mutex_unlock(&(data->lock_death));
			}
			else
				pthread_mutex_unlock(&(data->lock_last[i]));
			i++;
		}
		usleep(1000);
	}
	i = 0;
	while (i < data->num_p)
		pthread_join(philos[i++].pthread, NULL);
	return 0;
}
