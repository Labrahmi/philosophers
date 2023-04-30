/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:30:23 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/30 00:36:57 by ylabrahm         ###   ########.fr       */
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

typedef pthread_mutex_t t_mutex_t;

typedef struct s_data
{
	long int	start;
	int			is_dead;
	t_mutex_t	*forks;
	t_mutex_t	lock_death;
	t_mutex_t	*lock_last;
	int			num_p;
	int			die;
	int			eat;
	int			slp;
	int			num_e;

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
// int		ft_allocate_data(t_philo **philos, t_data **data);
int		ft_check_args(int argc, const char **argv, t_data *data);

#endif
