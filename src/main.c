/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:10:15 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/07 12:58:19 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	check_arg(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		if (!arg[i][0])
			return (EXIT_FAILURE);
		j = 0;
		while (arg[i][j])
		{
			if (!(arg[i][j] >= '0' && arg[i][j] <= '9'))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	free_mutex(t_data *data, int var)
{
	int	i;

	if (var == -1)
		init_mutex(data);
	i = -1;
	while (++i < data->philo_count)
		pthread_mutex_destroy(&data->fork[i].mutex);
	pthread_mutex_destroy(&data->m_meal);
	pthread_mutex_destroy(&data->m_write);
	pthread_mutex_destroy(&data->m_dead);
	pthread_mutex_destroy(&data->m_fork);
	pthread_mutex_destroy(&data->m_win);
	pthread_mutex_destroy(&data->m_t_eat);
	free(data->philo);
	free(data->fork);
}

static void	wait_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
		pthread_join(data->philo[i].thread, NULL);
	free_mutex(data, 0);
}

static void	start_thread(t_data *data)
{
	int		i;
	void	*func;

	i = -1;
	if (data->philo_count == 1)
		func = thread_1;
	else
		func = thread;
	data->start_time = get_time();
	while (++i < data->philo_count)
	{
		data->philo[i].last_meal = data->start_time;
		if (pthread_create(&data->philo[i].thread, NULL, \
		func, &data->philo[i]) != 0)
		{
			free_mutex(data, 0);
			exit(print_error("Error: Failed to create thread.", EXIT_FAILURE));
		}
	}
	if (func == thread)
		death_checker(data);
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	if (argc < MIN_ARGS || argc > MAX_ARGS)
		return (print_error("Error: Argument error.", EXIT_FAILURE));
	if (check_arg(argv) == EXIT_FAILURE)
		return (print_error("Error: Argument error.", EXIT_FAILURE));
	i = init_data(&data, argc, argv);
	if (i == 0 || i == -1)
		return (free_mutex(&data, i), EXIT_FAILURE);
	start_thread(&data);
	wait_threads(&data);
	return (EXIT_SUCCESS);
}
