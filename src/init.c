/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:10:21 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/07 12:53:43 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_atoi(const char *str)
{
	int	neg;
	int	i;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while ((str[i] <= '\r' && str[i] >= '\t' ) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

static int	init_gen_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->m_meal, NULL))
		return (print_error("Mutex initialization failed.", EXIT_FAILURE));
	if (pthread_mutex_init(&data->m_write, NULL))
		return (print_error("Mutex initialization failed.", EXIT_FAILURE));
	if (pthread_mutex_init(&data->m_write, NULL))
		return (print_error("Mutex initialization failed.", EXIT_FAILURE));
	if (pthread_mutex_init(&data->m_dead, NULL))
		return (print_error("Mutex initialization failed.", EXIT_FAILURE));
	if (pthread_mutex_init(&data->m_fork, NULL))
		return (print_error("Mutex initialization failed.", EXIT_FAILURE));
	if (pthread_mutex_init(&data->m_win, NULL))
		return (print_error("Mutex initialization failed.", EXIT_FAILURE));
	if (pthread_mutex_init(&data->m_t_eat, NULL))
		return (print_error("Mutex initialization failed.", EXIT_FAILURE));
	return (1);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	data->fork = malloc(sizeof(t_fork) * data->philo_count);
	if (!data->fork)
		return (print_error("Malloc failed.", EXIT_FAILURE));
	while (++i < data->philo_count)
	{
		if (pthread_mutex_init(&data->fork[i].mutex, NULL))
			return (print_error("Mutex initialization failed.", EXIT_FAILURE));
		data->fork[i].taken_by = 0;
	}
	return (init_gen_mutex(data));
}

static int	init_philo(t_data *data)
{
	int	i;

	i = -1;
	data->philo = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philo)
		return (print_error("Error: Memory allocation error.", 1));
	while (++i < data->philo_count)
	{
		data->philo[i].id = i + 1;
		data->philo[i].times_eat = 0;
		data->philo[i].right = i;
		data->philo[i].left = (i + 1) % data->philo_count;
		data->philo[i].last_meal = 0;
		data->philo[i].data = data;
	}
	return (1);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->philo_count = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->max_eat = -1;
	if (argc == MAX_ARGS)
		data->max_eat = ft_atoi(argv[5]);
	data->died = 0;
	data->win = 0;
	if (data->philo_count < 1 || data->die_time < 0 || data->eat_time < 0
		|| data->sleep_time < 0 || (argc == MAX_ARGS && data->max_eat < 1)
		|| data->sleep_time >= INT_MAX || data->die_time >= INT_MAX
		|| data->eat_time >= INT_MAX
		|| (argc == MAX_ARGS && data->max_eat >= INT_MAX))
		return (print_error("Error: Argument error.", -1));
	return (init_mutex(data) * init_philo(data));
}
