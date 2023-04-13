/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:27:43 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/12 17:08:42 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*execute_ths(void *arg)
{
	t_philo	philos;

	philos = (*(t_philo *) arg);
	printf("THREADS:======> '%d'\n", *(philos.is_dead));
	return 0;
}

void	ft_launch_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < NUM)
	{
		philos[i].id = i;
		pthread_create(&(philos[i].pthread), NULL, execute_ths, &(philos[i]));
		i += 2;
	}
	usleep(500);
	i = 1;
	while (i < NUM)
	{
		philos[i].id = i;
		pthread_create(&(philos[i].pthread), NULL, execute_ths, &(philos[i]));
		i += 2;
	}
}
