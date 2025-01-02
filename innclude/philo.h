/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:59:10 by maxence           #+#    #+#             */
/*   Updated: 2025/01/02 14:42:08 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>

# define RED "\033[0;31m"
# define DEF_COLOR "\033[0m"
# define PHILO_MAX 300

# define MIN_ARGS 5
# define MAX_ARGS 6



typedef struct s_fork
{
	pthread_mutex_t		mutex;
	int					taken_by;
}						t_fork;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	int					times_eat;
	int					left;
	int					right;
	long int			last_meal;
	struct s_data		*data;
}						t_philo;

typedef struct s_data
{
	int					philo_count;
	int					die_time;
	int					eat_time;
	int					sleep_time;
	int					max_eat;
	int					died;
	int					win;
	long int			start_time;
	pthread_mutex_t		m_meal;
	pthread_mutex_t		m_dead;
	pthread_mutex_t		m_win;
	pthread_mutex_t		m_write;
	pthread_mutex_t		m_fork;
	pthread_mutex_t		m_t_eat;
	t_philo				*philo;
	t_fork				*fork;
}						t_data;

t_data	*get_data(int argc, char **argv);
t_data	*get_var_data(void);

// utils

int		ft_isdigit(int character);
int				ft_atoi( const char *str);
int				print_error(char *str, int i);
long int		get_time(void);
long int		now(t_philo *philo);
void			*thread(void *var);
void			*thread_1(void *var);
int				init_data(t_data *data, int argc, char **argv);
void			print(t_data *data, int id, char *str);
int				check_died(t_data *data);
int				check_win(t_data *data);
void			start_thread(t_data *data);
void			smart_sleep(long int time, t_data *data);
int				is_reached_max_eat(t_philo *philo);
void			win_checker(t_data *data);
void			death_checker(t_data *data);
// int				init_mutex(t_data *data);


#endif
