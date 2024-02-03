/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:32:38 by rdemiray          #+#    #+#             */
/*   Updated: 2024/01/30 12:30:16 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_ph	**ph;

	if (check_number(argv))
	{
		write(2, "error: argument is invalid", 27);
		return (0);
	}
	data = malloc(sizeof(t_data));
	if (!data)
	{
		write(2, "Error: Allocation error\n", 25);
		return (0);
	}
	if (argc != 5 && argc != 6)
	{
		write(2, "Error: argument number is wrong\n", 33);
		return (0);
	}
	data = data_init(argc, argv, data);
	ph = philo_init(data);
	thread(ph);
}
