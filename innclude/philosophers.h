/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:59:10 by maxence           #+#    #+#             */
/*   Updated: 2024/12/27 15:17:27 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdint.h> // Pour int64_t (timestamps)
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data t_data;

typedef struct s_philo
{
	int				id;                
	int				meals_eaten;       
	int64_t			last_meal_time;    
	pthread_t		thread;            
	pthread_mutex_t	*left_fork;        
	pthread_mutex_t	*right_fork;      
	t_data			*data;       
}	t_philo;

typedef struct s_data
{
	int				nb_philo;          // Nombre total de philosophes
	int				time_to_die;       // Temps avant qu'un philosophe ne meure sans manger
	int				time_to_eat;       // Temps nécessaire pour manger
	int				time_to_sleep;     // Temps pour dormir après avoir mangé
	int				nb_must_eat;       // Nombre minimum de repas à manger (optionnel)
	int64_t			start_time;        // Timestamp du début de la simulation
	pthread_mutex_t	*forks;            // Tableau de mutex pour les fourchettes
	pthread_mutex_t	print_lock;        // Mutex pour l'affichage
	pthread_mutex_t	death_lock;        // Mutex pour vérifier si un philosophe est mort
	int				someone_died;      // Flag pour indiquer si un philosophe est mort
	t_philo			*philos;           // Tableau des philosophes
}	t_data;

#endif
