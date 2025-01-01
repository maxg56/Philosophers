/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:10:15 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/01 15:04:17 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_arg_content(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_valid_args(char **argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_arg_content(argv[1]) == 1)
		return (exit_error(ERR_INVALID_PHILOS_NUM), 1);
	if (ft_atoi(argv[2]) <= 0 || check_arg_content(argv[2]) == 1)
		return (exit_error(ERR_INVALID_TIME_TO_DIE), 1);
	if (ft_atoi(argv[3]) <= 0 || check_arg_content(argv[3]) == 1)
		return (exit_error(ERR_INVALID_TIME_TO_EAT), 1);
	if (ft_atoi(argv[4]) <= 0 || check_arg_content(argv[4]) == 1)
		return (exit_error(ERR_INVALID_TIME_TO_SLEEP), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_arg_content(argv[5]) == 1))
		return (exit_error(ERR_INVALID_NUM_MEALS), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < MIN_ARGS || argc > MAX_ARGS)
		exit_error(ERR_WRONG_ARG_COUNT);
	if (check_valid_args(argv))
		return (1);
	data = get_data(argc, argv);
	if (!data)
		return (exit_error(ERR_INVALID_PHILOS_NUM), 1);
	return (0);
}
