/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Erore.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:19:14 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/01 15:06:19 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

const char	*get_error_message(t_error err)
{
	static const char	*messages[] = {
		"Invalid philosophers number\n",
		"Invalid time to die\n",
		"Invalid time to eat\n",
		"Invalid time to sleep\n",
		"Invalid number of times each philosopher must eat\n",
		"Wrong number of arguments\n"
	};

	return (messages[err]);
}

void	exit_error(t_error *err)
{
	const char	*message;
	int			i;

	message = get_error_message(err);
	i = 0;
	write(2, RED"Error:\n", 7);
	write(2, message, ft_strlen(message));
	write(2, "\n"DEF_COLOR, 5);
	free(get_var_data());
	exit(1);
}

void	error(t_error *message)
{
	printf(RED"Error:\n%s\n"DEF_COLOR, get_error_message(message));
}


