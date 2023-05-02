/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:29:24 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/05/02 16:40:20 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_die(t_main_vars *vars, int *done, t_philo *philos)
{
	int	i;

	i = 0;
	while ((i < vars->data->num_p) && *done)
	{
		pthread_mutex_lock(&(vars->data->lock_last[i]));
		if (get_time() - philos[i].last_eat > vars->data->die)
		{
			pthread_mutex_unlock(&(vars->data->lock_last[i]));
			pthread_mutex_lock(&(vars->data->lock_death));
			vars->data->is_dead = 1;
			printf("%ld %d died\n", get_time() - vars->data->start, (i + 1));
			*done = 0;
			pthread_mutex_unlock(&(vars->data->lock_death));
		}
		else
			pthread_mutex_unlock(&(vars->data->lock_last[i]));
		vars->tot_eats += philos[i].eats;
		i++;
	}
}

void	check_eats(t_main_vars *vars, int *done)
{
	int	i;

	i = 0;
	while (i < vars->data->num_p)
	{
		pthread_mutex_lock(&(vars->data->lock_eats[i]));
		if (vars->tot_eats >= vars->data->num_e * vars->data->num_p
			&& (vars->data->num_e != -1))
		{
			pthread_mutex_unlock(&(vars->data->lock_eats[i]));
			pthread_mutex_lock(&(vars->data->lock_death));
			vars->data->is_dead = 1;
			*done = 0;
			pthread_mutex_unlock(&(vars->data->lock_death));
		}
		else
			pthread_mutex_unlock(&(vars->data->lock_eats[i]));
		i++;
	}
}

void	init_variables(int *done, t_main_vars *vars, t_philo *philos)
{
	init_dead_mutex(vars->data, philos);
	ft_launch_threads(philos);
	*done = 1;
}

int	free_all(t_main_vars *vars, t_philo *philos)
{
	free(vars->data->forks);
	free(vars->data->lock_last);
	free(vars->data->lock_eats);
	free(philos);
	free(vars->data);
	return (0);
}

int	main(int argc, char const *argv[])
{
	int			i;
	int			done;
	t_main_vars	vars;
	t_philo		*philos;

	vars.data = (t_data *) malloc(sizeof(t_data));
	if (!(ft_check_args(argc, argv, vars.data)))
		return (0);
	philos = (t_philo *) malloc(sizeof(t_philo) * vars.data->num_p);
	vars.data->forks = (t_mu *) malloc(sizeof(t_mu) * vars.data->num_p);
	vars.data->lock_last = (t_mu *) malloc(sizeof(t_mu) * vars.data->num_p);
	vars.data->lock_eats = (t_mu *) malloc(sizeof(t_mu) * vars.data->num_p);
	init_variables(&done, &vars, philos);
	while (done)
	{
		vars.tot_eats = 0;
		check_die(&vars, &done, philos);
		check_eats(&vars, &done);
		usleep(1000);
	}
	i = 0;
	while (i < vars.data->num_p)
		pthread_join(philos[i++].pthread, NULL);
	return (free_all(&vars, philos));
}
