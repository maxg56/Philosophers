/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:59:10 by maxence           #+#    #+#             */
/*   Updated: 2025/01/01 14:59:41 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>
# include <stdint.h>

# define RED "\033[0;31m"
# define DEF_COLOR "\033[0m"
# define PHILO_MAX 300

# define MIN_ARGS 5
# define MAX_ARGS 6

typedef enum e_error
{
	ERR_INVALID_PHILOS_NUM,
	ERR_INVALID_TIME_TO_DIE,
	ERR_INVALID_TIME_TO_EAT,
	ERR_INVALID_TIME_TO_SLEEP,
	ERR_INVALID_NUM_MEALS,
	ERR_WRONG_ARG_COUNT
}	t_error;

const char	*get_error_message(t_error err);

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
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int64_t			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
	int				someone_died;
	t_philo			**philos;
}	t_data;

t_data	*get_data(int argc, char **argv);
t_data	*get_var_data(void);

// utils

int		ft_isdigit(int character);
int		ft_atoi(const char *str);
void	exit_error(t_error *message);
void	error(t_error *message);
void	free_data(t_data *data);

#endif
