/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:32:13 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/07 15:27:18 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	is_reached_max_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_t_eat);
	if (philo->times_eat >= philo->data->max_eat)
	{
		pthread_mutex_unlock(&philo->data->m_t_eat);
		return (EXIT_FAILURE);
	}
	pthread_mutex_unlock(&philo->data->m_t_eat);
	return (EXIT_SUCCESS);
}

int	check_win(t_data *data)
{
	pthread_mutex_lock(&data->m_win);
	if (data->win)
	{
		pthread_mutex_unlock(&data->m_win);
		return (EXIT_FAILURE);
	}
	else
	{
		pthread_mutex_unlock(&data->m_win);
		return (EXIT_SUCCESS);
	}
}

int	win_checker(t_data *data, int update_win)
{
	int	i;

	i = 0;
	while (data->max_eat != UNLIMITED_MEALS && i < data->philo_count
		&& is_reached_max_eat(&data->philo[i]))
		i++;
	if (i == data->philo_count)
	{
		if (update_win)
		{
			pthread_mutex_lock(&data->m_win);
			data->win = 1;
			pthread_mutex_unlock(&data->m_win);
			pthread_mutex_lock(&data->m_write);
			printf("Each philosopher ate at least %d time(s).\n", \
			data->max_eat);
			pthread_mutex_unlock(&data->m_write);
		}
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	check_died(t_data *data)
{
	pthread_mutex_lock(&data->m_dead);
	if (data->died)
		return (pthread_mutex_unlock(&data->m_dead), EXIT_FAILURE);
	else
		return (pthread_mutex_unlock(&data->m_dead), EXIT_SUCCESS);
}

void	death_checker(t_data *data)
{
	int	i;

	while (!check_win(data))
	{
		i = -1;
		while (++i < data->philo_count && !check_died(data))
		{
			pthread_mutex_lock(&data->m_meal);
			if (get_time() - data->philo[i].last_meal > data->die_time)
			{
				pthread_mutex_lock(&data->m_dead);
				data->died = 1;
				pthread_mutex_unlock(&data->m_dead);
				pthread_mutex_lock(&data->m_write);
				printf("%ld %d %s\n", get_time() - data->start_time,
					data->philo[i].id, "died");
				pthread_mutex_unlock(&data->m_write);
			}
			pthread_mutex_unlock(&data->m_meal);
			usleep(200);
		}
		if (check_died(data))
			break ;
		win_checker(data, 1);
	}
}
