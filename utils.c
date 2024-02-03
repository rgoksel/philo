/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:38:11 by rdemiray          #+#    #+#             */
/*   Updated: 2024/01/29 12:38:27 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	current_time(void)
{
	struct timeval	time;
	long long int	ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	ft_usleep(t_ph *ph, long long time_eat)
{
	long long	start;

	start = current_time();
	while (!(ph->data->is_dead))
	{
		if (current_time() - start >= time_eat)
			break ;
		usleep(50);
	}
}

long long	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}

void	print_status(t_ph *ph, const char *msg)
{
	t_data	*data;

	data = ph->data;
	pthread_mutex_lock(&data->mtx_write);
	if (!(data->is_dead))
	{
		printf("%lld ", current_time() - data->ms_start);
		printf("%d %s", ph->i + 1, msg);
	}
	pthread_mutex_unlock(&data->mtx_write);
}
