/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:27:43 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/13 23:12:51 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*execute_ths(void *arg)
{
	t_philo		*philo;
	long int	start;
	int			id, r_id;

	philo = (t_philo *) arg;
	start = philo->data->start;
	id = philo->id;
	r_id = (id + 1) % NUM;
	while (1)
	{
		/* Check-Death */
		pthread_mutex_lock(&(philo->data->lock_death));
		if (philo->data->is_dead == 1)
		{
			pthread_mutex_unlock(&(philo->data->lock_death));
			break;
		}
		pthread_mutex_unlock(&(philo->data->lock_death));
		/* Think */
		printf("%ld %d is thinking\n", get_time() - start, (id + 1));
		/* Take forks */
		pthread_mutex_lock(&(philo->data->forks[id]));
		printf("%ld %d has taken a fork\n", get_time() - start, (id + 1));
		pthread_mutex_lock(&(philo->data->forks[r_id]));
		printf("%ld %d has taken a fork\n", get_time() - start, (id + 1));
		/* Eat */
		printf("%ld %d is eating\n", get_time() - start, (id + 1));
		pthread_mutex_lock(&(philo->data->lock_last[id]));
		philo->last_eat = get_time();
		pthread_mutex_unlock(&(philo->data->lock_last[id]));
		my_sleep(EAT);
		/* Put forks */
		pthread_mutex_unlock(&(philo->data->forks[r_id]));
		pthread_mutex_unlock(&(philo->data->forks[id]));
		/* Sleep */
		printf("%ld %d is sleeping\n", get_time() - start, (id + 1));
		my_sleep(SLP);
	}
	return 0;
}

void	ft_launch_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < NUM)
	{
		philos[i].id = i;
		philos[i].last_eat = get_time();
		pthread_create(&(philos[i].pthread), NULL, execute_ths, &(philos[i]));
		usleep(NUM / 40);
		i += 2;
	}
	usleep(250);
	i = 1;
	while (i < NUM)
	{
		philos[i].id = i;
		philos[i].last_eat = get_time();
		pthread_create(&(philos[i].pthread), NULL, execute_ths, &(philos[i]));
		usleep(NUM / 40);
		i += 2;
	}
}
