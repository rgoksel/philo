/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:35:55 by rdemiray          #+#    #+#             */
/*   Updated: 2024/01/30 12:25:39 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*data_init(int ac, char **av, t_data *data)
{
	data->num_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->max_eat = -1;
	if (ac == 6)
		data->max_eat = ft_atoi(av[5]);
	if (data->time_die < 1 || data->time_eat < 1 || data->time_sleep < 1
		|| data->num_philo < 1 || (ac == 6 && data->max_eat < 1))
	{
		write(2, "Error: Arguments is invalid\n", 29);
		free(data);
		return (0);
	}
	data->forks = fork_init(ft_atoi(av[1]), data);
	data->ms_start = current_time();
	data->is_dead = 0;
	data->is_all_eaten = 0;
	return (data);
}

pthread_mutex_t	*fork_init(long long num, t_data *data)
{
	long long		i;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * num);
	if (!forks)
	{
		free(data);
		write(2, "Error: Allocation error\n", 25);
		return (NULL);
	}
	i = -1;
	while (++i < num)
		pthread_mutex_init(&forks[i], NULL);
	pthread_mutex_init(&data->mtx_write, NULL);
	pthread_mutex_init(&data->mtx_eat, NULL);
	return (forks);
}

t_ph	**philo_init(t_data *data)
{
	t_ph	**ph;
	int		i;

	ph = (t_ph **)malloc(sizeof(t_ph *) * data->num_philo);
	if (!ph)
	{
		free(data->forks);
		free(data);
		error("Error: Allocation error\n");
	}
	i = 0;
	while (i < data->num_philo)
	{
		ph[i] = (t_ph *)malloc(sizeof(t_ph));
		ph[i]->i = i;
		ph[i]->data = data;
		ph[i]->nbr_eat = 0;
		i++;
	}
	return (ph);
}
