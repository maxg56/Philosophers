/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:39:56 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/03 14:57:48 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
					data->philo[i].id, "died.");
				pthread_mutex_unlock(&data->m_write);
			}
			pthread_mutex_unlock(&data->m_meal);
			usleep(200);
		}
		if (check_died(data))
			break ;
		win_checker(data);
	}
}

int	check_died(t_data *data)
{
	pthread_mutex_lock(&data->m_dead);
	if (data->died)
	{
		pthread_mutex_unlock(&data->m_dead);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&data->m_dead);
		return (0);
	}
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

void	smart_sleep(long int time, t_data *data)
{
	long int	i;

	i = get_time();
	while (get_time() - i < time)
	{
		if (check_died(data) || check_win(data))
			break ;
		usleep(100);
	}
}

int	is_reached_max_eat(t_philo *philo)
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
