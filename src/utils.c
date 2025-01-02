/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:10:09 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/02 14:39:35 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../innclude/philo.h"

int	ft_atoi(const char *str)
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
			neg *long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

void	win_checker(t_data *data)
{
	int	i;

	i = 0;
	while (data->max_eat != -1 && i < data->philo_count
		&& is_reached_max_eat(&data->philo[i]))
		i++;
	if (i == data->philo_count)
	{
		pthread_mutex_lock(&data->m_win);
		data->win = 1;
		pthread_mutex_unlock(&data->m_win);
		pthread_mutex_lock(&data->m_write);
		printf("Each philosopher ate at least %d time(s).\n", data->max_eat);
		pthread_mutex_unlock(&data->m_write);
	}
}= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}

int	print_error(char *str, int i)
{
	printf("%s\n", str);
	return (i);
}

long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

void	win_checker(t_data *data)
{
	int	i;

	i = 0;
	while (data->max_eat != -1 && i < data->philo_count
		&& is_reached_max_eat(&data->philo[i]))
		i++;
	if (i == data->philo_count)
	{
		pthread_mutex_lock(&data->m_win);
		data->win = 1;
		pthread_mutex_unlock(&data->m_win);
		pthread_mutex_lock(&data->m_write);
		printf("Each philosopher ate at least %d time(s).\n", data->max_eat);
		pthread_mutex_unlock(&data->m_write);
	}
}