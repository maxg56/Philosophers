/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:35:03 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/07 15:25:16 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	release_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->taken_by = 0;
	pthread_mutex_unlock(&fork->mutex);
}

static int	take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	if (!fork->taken_by)
	{
		print(philo->data, philo->id, "has taken a fork");
		fork->taken_by = philo->id;
	}
	if (fork->taken_by == philo->id)
	{
		pthread_mutex_unlock(&fork->mutex);
		return (1);
	}
	pthread_mutex_unlock(&fork->mutex);
	return (0);
}

void	eat(t_philo *philo)
{
	if (!win_checker(philo->data, 0))
		return ;
	if (check_died(philo->data))
		return ;
	while (!take_fork(philo, &philo->data->fork[philo->left]))
		usleep(USLEEP_INTERVAL);
	while (!take_fork(philo, &philo->data->fork[philo->right]))
		usleep(USLEEP_INTERVAL);
	if (!win_checker(philo->data, 0))
	{
		release_fork(&philo->data->fork[philo->left]);
		release_fork(&philo->data->fork[philo->right]);
		return ;
	}
	pthread_mutex_lock(&philo->data->m_meal);
	print(philo->data, philo->id, "is eating");
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->m_meal);
	smart_sleep(philo->data->eat_time, philo->data);
	pthread_mutex_lock(&philo->data->m_t_eat);
	philo->times_eat++;
	pthread_mutex_unlock(&philo->data->m_t_eat);
	release_fork(&philo->data->fork[philo->left]);
	release_fork(&philo->data->fork[philo->right]);
}

void	*thread_1(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	print(philo->data, philo->id, "has taken a fork");
	usleep(philo->data->die_time * PHILO_DELAY_1);
	print(philo->data, philo->id, "died");
	return (NULL);
}

void	*thread(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	if (philo->id % 2 == 0)
		usleep(PHILO_DELAY);
	while (!check_died(philo->data))
	{
		if (check_win(philo->data))
			break ;
		eat(philo);
		print(philo->data, philo->id, "is sleeping");
		smart_sleep(philo->data->sleep_time, philo->data);
		print(philo->data, philo->id, "is thinking");
	}
	return (NULL);
}
