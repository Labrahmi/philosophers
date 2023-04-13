/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:28:21 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/13 23:02:27 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_allocate_data(t_philo **philos, t_data **data)
{
	*philos = malloc(sizeof(t_philo) * NUM);
	*data = malloc(sizeof(t_data));
	(*data)->forks = malloc(sizeof(pthread_mutex_t) * NUM);
	(*data)->lock_last = malloc(sizeof(pthread_mutex_t) * NUM);
	// (*data)->is_dead = malloc(sizeof(int *));
	// (*data)->lock_death = malloc(sizeof(pthread_mutex_t *));
	return (0);
}
