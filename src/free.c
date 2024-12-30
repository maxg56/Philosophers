/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:14:46 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/30 14:17:29 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks)
	{
		while (i < data->nb_philo)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
	if (data->philos)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			free(data->philos[i]);
			i++;
		}
	}
	free(data);
}
