/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:30:23 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/12 16:23:31 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>

# define NUM 30
# define DIE 200
# define SLP 100
# define EAT 100

typedef struct s_mutex
{
	pthread_mutex_t	death;
}	t_mutex;

typedef struct s_philo
{
	int				id;
	int				*is_dead;
	pthread_t		pthread;
	pthread_mutex_t	*lock_death;
} t_philo;

void	my_sleep(int ms);
long	get_time(void);
void    ft_launch_threads(t_philo *philos);
void	*execute_ths(void *arg);
void	init_dead_mutex(t_mutex *mutex, t_philo *philos, int *is_dead);

#endif
