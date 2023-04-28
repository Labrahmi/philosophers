/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:30:23 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/28 23:54:44 by ylabrahm         ###   ########.fr       */
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

# define NUM 200
# define DIE 211
# define EAT 100
# define SLP 100

typedef pthread_mutex_t mutex_t;

typedef struct s_data
{
	long int	start;
	int			is_dead;
	mutex_t		*forks;
	mutex_t		lock_death;
	mutex_t		*lock_last;
	int			num;
	int			die;
	int			eat;
	int			slp;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		pthread;
	long int		last_eat;
	t_data			*data;
} t_philo;

void	my_sleep(int ms, t_philo *philo);
long	get_time(void);
void    ft_launch_threads(t_philo *philos);
void	*execute_ths(void *arg);
void	init_dead_mutex(t_data *data, t_philo *philos);
int		ft_allocate_data(t_philo **philos, t_data **data);
int		ft_check_args(int argc, const char **argv, t_data *data);

#endif
