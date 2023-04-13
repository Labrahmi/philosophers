/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:30:23 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/13 23:14:56 by ylabrahm         ###   ########.fr       */
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

# define NUM 5
# define DIE 250
# define EAT 150
# define SLP 100

typedef struct s_data
{
	int				is_dead;
	pthread_mutex_t	lock_death;
	long int		start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*lock_last;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		pthread;
	long int		last_eat;
	t_data			*data;
} t_philo;

void	my_sleep(int ms);
long	get_time(void);
void    ft_launch_threads(t_philo *philos);
void	*execute_ths(void *arg);
void	init_dead_mutex(t_data *data, t_philo *philos);
int		ft_allocate_data(t_philo **philos, t_data **data);

#endif
