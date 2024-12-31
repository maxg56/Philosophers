/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Erore.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:19:14 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/31 15:00:41 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_error(char *message)
{
	printf(RED"Error:\n%s\n"DEF_COLOR, message);
	free(get_var_data());
	exit(1);
}

void	error(char *message)
{
	printf(RED"Error:\n%s\n"DEF_COLOR, message);
}


