/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:10:09 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/07 15:44:10 by mgendrot         ###   ########.fr       */
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
	write(2, "\n", 1);
	write(2, DEF_COLOR, ft_strlen(DEF_COLOR));
	return (i);
}

long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

void	print(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&data->m_write);
	if (!check_died(data) && !check_win(data))
	{
		printf("%ld %d %s\n", get_time() - data->start_time, id, str);
	}
	pthread_mutex_unlock(&data->m_write);
}

void	smart_sleep(long int time, t_data *data)
{
	long int	i;

	i = get_time();
	while (get_time() - i < time)
	{
		if (check_died(data) || check_win(data))
			break ;
		usleep(USLEEP_INTERVAL);
	}
}
