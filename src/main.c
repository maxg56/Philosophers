/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:10:15 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/30 20:57:10 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
		exit_error("Wrong number of arguments");
	data = get_data(argc, argv);

	return (0);
}
