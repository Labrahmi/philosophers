/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:30:23 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/05/02 16:10:43 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mu;

typedef struct s_data
{
	long int	start;
	int			is_dead;
	t_mu		*forks;
	t_mu		lock_death;
	t_mu		*lock_last;
	t_mu		*lock_eats;
	int			num_p;
	int			die;
	int			eat;
	int			slp;
	int			num_e;
}	t_data;

typedef struct s_philo
{
	int			id;
	pthread_t	pthread;
	long int	last_eat;
	t_data		*data;
	int			eats;
}	t_philo;

typedef struct s_main_vars
{
	int			tot_eats;
	t_data		*data;
}	t_main_vars;

void	my_sleep(int ms, t_philo *philo);
long	get_time(void);
void	ft_launch_threads(t_philo *philos);
void	*execute_ths(void *arg);
void	init_dead_mutex(t_data *data, t_philo *philos);
int		ft_check_args(int argc, const char **argv, t_data *data);
void	ft_take_forks(t_philo *philo, long int start, int id, int r_id);
void	ft_eat(t_philo *philo, long int start, int id, int r_id);
void	ft_print(t_philo *philo, long int start, int id, char *message);
int		ft_check_death(t_philo *philo);

#endif
