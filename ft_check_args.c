/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:48:04 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/04/29 23:26:30 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

static long long	helper(const char *str, long long some, int i, int sign)
{
	while (ft_isdigit(str[i]))
	{
		some = (some * 10) + (str[i] - '0');
		i++;
		if (some < 0)
		{
			if (sign != -1)
				return (-1);
			else
				return (0);
		}
	}
	return (some);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	some;

	i = 0;
	sign = 1;
	some = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (helper(str, some, i, sign) * sign);
}

int ft_check_args(int argc, const char **argv, t_data *data)
{
	int	i;

	if (!((argc == 5) || (argc == 6)))
		return (0);
	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i++]) <= 0)
			return (0);
	}
	data->num_p = ft_atoi(argv[1]);
	data->die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->slp = ft_atoi(argv[4]);
	data->num_e = -1;
	if (argc == 6)
		data->num_e = ft_atoi(argv[5]);
	return (1);
}