/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:04:33 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/01 14:05:10 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void   est(t_philo *philo)
{
   printf("%d %d is eating\n", philo->id, get_time());
   usleep(philo->data->time_to_eat * 1000);
   philo->last_meal = get_time();
   philo->meals++;
}