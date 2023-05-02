/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:27:43 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/05/02 00:21:22 by ylabrahm         ###   ########.fr       */
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
	pthread_mutex_lock(&(philo->data->lock_death));
	if ((philo->data->is_dead) == 1)
	{
		pthread_mutex_unlock(&(philo->data->lock_death));
		return ;
	}
	printf("%ld %d %s\n", get_time() - start, (id + 1), message);
	pthread_mutex_unlock(&(philo->data->lock_death));
}

void	*execute_ths(void *arg)
{
	t_philo		*philo;
	long int	start;
	int			id;
	int			r_id;

	philo = (t_philo *) arg;
	start = philo->data->start;
	id = philo->id;
	r_id = (id + 1) % philo->data->num_p;
	while (1)
	{
		if (ft_check_death(philo))
			return (NULL);
		ft_print(philo, start, id, "is thinking");
		ft_take_forks(philo, start, id, r_id);
		ft_eat(philo, start, id, r_id);
		pthread_mutex_unlock(&(philo->data->forks[r_id]));
		pthread_mutex_unlock(&(philo->data->forks[id]));
		ft_print(philo, start, id, "is sleeping");
		if (ft_check_death(philo) == 0)
			my_sleep(philo->data->slp, philo);
	}
	return (0);
}

void	ft_launch_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->num_p)
	{
		philos[i].id = i;
		philos[i].last_eat = get_time();
		pthread_create(&(philos[i].pthread), NULL, execute_ths, &(philos[i]));
		usleep(philos[i].data->num_p * 2);
		i += 2;
	}
	usleep(500 + philos[0].data->num_p);
	i = 1;
	while (i < philos->data->num_p)
	{
		philos[i].id = i;
		philos[i].last_eat = get_time();
		pthread_create(&(philos[i].pthread), NULL, execute_ths, &(philos[i]));
		usleep(philos[i].data->num_p * 2);
		i += 2;
	}
}
