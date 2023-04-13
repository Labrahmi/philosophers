/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:29:24 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/12 18:05:51 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char const *argv[])
{
	int			i;
	int			is_dead;
	t_mutex		mutex;
	t_philo		*philos;

	philos = malloc(sizeof(t_philo) * NUM);
	init_dead_mutex(&mutex, philos, &(is_dead));
	ft_launch_threads(philos);
	i = 0;
	while (/* condition */)
	{
		/* code */
	}
	
	while (i < NUM)
		pthread_join(philos[i++].pthread, NULL);
	return 0;
}
