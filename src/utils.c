/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:10:09 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/03 15:05:28 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	print_error(char *str, int i)
{
	write(2, RED, ft_strlen(RED));
	write(2, str, ft_strlen(str));
	write(2, DEF_COLOR, ft_strlen(DEF_COLOR));
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
	while (data->max_eat != UNLIMITED_MEALS && i < data->philo_count
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

void	print(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&data->m_write);
	if (!check_died(data) && !check_win(data))
	{
		printf("%ld ms %d %s\n", get_time() - data->start_time, id, str);
	}
	pthread_mutex_unlock(&data->m_write);
}
