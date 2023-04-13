/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:23:26 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/12 11:33:23 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	my_sleep(int ms)
{
	long	start;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	start = get_time();
	while (1)
	{
		usleep(10);
		if ((get_time() - start) >= ms)
			return;
	}
}
