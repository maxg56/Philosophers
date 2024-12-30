/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:10:21 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/30 14:08:49 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*get_var_data(void)
{
	static t_data	*data = NULL;

	if (!data)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (NULL);
	}
	data->philos = NULL;
	return (data);
}

static t_data	*init_data(void)
{
	t_data	*data;

	data = get_var_data();
	data->nb_philo = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->nb_must_eat = -1;
	data->start_time = 0;
	data->forks = NULL;
	data->someone_died = 0;
	data->philos = NULL;
	return (data);
}

static t_philo	init_philo(int id, t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->meals_eaten = 0;
	philo->last_meal_time = 0;
	philo->left_fork = NULL;
	philo->right_fork = NULL;
	philo->data = data;
	return (philo);
}

static void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	while (i < data->nb_philo)
	{
		data->philos[i] = init_philo(i, data);
		if (!data->philos[i])
			return ;
		i++;
	}
}

t_data	*get_data(int argc, char **argv)
{
	t_data	*data;

	data = init_data();
	data->nb_philo = ft_atoi(argv[1]);
	init_philos(data);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_must_eat = ft_atoi(argv[5]);
	return (data);
}
