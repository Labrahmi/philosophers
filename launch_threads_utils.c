/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 00:20:44 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/05/02 16:34:38 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_forks(t_philo *philo, long int start, int id, int r_id)
{
	pthread_mutex_lock(&(philo->data->forks[id]));
	ft_print(philo, start, id, "has taken a fork");
	if (id == r_id)
		return ;
	pthread_mutex_lock(&(philo->data->forks[r_id]));
	ft_print(philo, start, id, "has taken a fork");
}

void	ft_eat(t_philo *philo, long int start, int id)
{
	ft_print(philo, start, id, "is eating");
	pthread_mutex_lock(&philo->data->lock_eats[id]);
	philo->eats += 1;
	pthread_mutex_unlock(&philo->data->lock_eats[id]);
	pthread_mutex_lock(&(philo->data->lock_last[id]));
	philo->last_eat = get_time();
	pthread_mutex_unlock(&(philo->data->lock_last[id]));
	if (ft_check_death(philo) == 0)
		my_sleep(philo->data->eat, philo);
}
