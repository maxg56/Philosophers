/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:10:15 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/02 13:56:34 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../innclude/philo.h"

static int	check_arg(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (!ft_isdigit(arg[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_mutex(t_data *data)
{
	int	i;

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

void	wait_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
		pthread_join(data->philo[i].thread, NULL);
	free_mutex(data);
}

void	start_thread(t_data *data)
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
		pthread_create(&data->philo[i].thread, NULL, func, &data->philo[i]);
	}
	if (func == thread)
		death_checker(data);
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	if (argc < MIN_ARGS || argc > MAX_ARGS)
		return (print_error("Error: Argument error.", 1));
	if (cehck_arg(argv) == 1)
		return (print_error("Error: Argument error.", 1));
	i = init_data(&data, argc, argv);
	if (i == 0 || i == -1)
	{
		free_mutex(&data, i);
		return (0);
	}
	start_thread(&data);
	wait_threads(&data);
	return (0);
}
