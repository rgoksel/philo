/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:33:52 by rdemiray          #+#    #+#             */
/*   Updated: 2024/01/29 13:36:52 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				max_eat;
	long long int	ms_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mtx_write;
	pthread_mutex_t	mtx_eat;
	int				is_dead;
	int				is_all_eaten;
}	t_data;

typedef struct s_ph
{
	pthread_t	th;
	int			i;
	t_data		*data;	
	int			nbr_eat;	
	long long	last_eat_t;

}	t_ph;

long long		ft_atoi(const char *str);
int				check_number(char **argv);
int				ft_isdigit(int s);
int				thread(t_ph **ph);
long long int	current_time(void);
t_ph			**philo_init(t_data *data);
void			print_status(t_ph *ph, const char *msg);
void			ft_usleep(t_ph *ph, long long time_eat);
void			free_all(t_ph **ph);
t_data			*data_init(int ac, char **av, t_data *data);
void			error(char *msg);
pthread_mutex_t	*fork_init(long long num, t_data *data);

#endif