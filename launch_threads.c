/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:27:43 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/14 01:55:46 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->lock_death));
	if ((philo->data->is_dead) == 1)
	{
		pthread_mutex_unlock(&(philo->data->lock_death));
		return (1);
	}
	pthread_mutex_unlock(&(philo->data->lock_death));
	return (0);
}

void	ft_print(t_philo *philo, long int start, int id, char *message)
{
	// if (ft_check_death(philo) == 0)
		printf("%ld %d %s\n", get_time() - start, (id + 1), message);
}

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
		if (ft_check_death(philo))
			return (NULL);
		/* Think */
		ft_print(philo, start, id, "is thinking");
		/* Take forks */
		pthread_mutex_lock(&(philo->data->forks[id]));
		ft_print(philo, start, id, "has taken a fork");
		if (NUM == 1)
		{
			pthread_mutex_unlock(&(philo->data->forks[id]));		
			return (NULL);
		}
		pthread_mutex_lock(&(philo->data->forks[r_id]));
		ft_print(philo, start, id, "has taken a fork");
		/* Eat */
		ft_print(philo, start, id, "is eating");
		pthread_mutex_lock(&(philo->data->lock_last[id]));
		philo->last_eat = get_time();
		pthread_mutex_unlock(&(philo->data->lock_last[id]));
		if (ft_check_death(philo) == 0)
			my_sleep(EAT, philo);
		/* Put forks */
		pthread_mutex_unlock(&(philo->data->forks[r_id]));
		pthread_mutex_unlock(&(philo->data->forks[id]));
		/* Sleep */
		ft_print(philo, start, id, "is sleeping");
		if (ft_check_death(philo) == 0)
			my_sleep(SLP, philo);
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
		usleep(NUM / 20);
		i += 2;
	}
	usleep(100 + (NUM / 10));
	i = 1;
	while (i < NUM)
	{
		philos[i].id = i;
		philos[i].last_eat = get_time();
		pthread_create(&(philos[i].pthread), NULL, execute_ths, &(philos[i]));
		usleep(NUM / 20);
		i += 2;
	}
}
