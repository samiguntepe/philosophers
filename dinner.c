/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:48:18 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/13 23:00:08 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <pthread.h>

void	*dinner(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	if (philos->id % 2 != 0 && philos->args->number_of_philosophers != 1)
	{
		write_term(philos->id, 4, philos);
		usleep(1000);
	}
	while (1)
	{
		if (philos->eat_count < philos->args->number_of_must_eat
			|| philos->args->number_of_must_eat == 0)
		{
			if (eating(philos))
				break ;
		}
		if (sleep_and_think(philos))
			return (NULL);
	}
	return (NULL);
}

int	sleep_and_think(t_philo *philos)
{
	pthread_mutex_lock(&philos->args->mutex_die);
	if (philos->args->died == 1 && philos->eat_count
		>= philos->args->number_of_must_eat)
	{
		pthread_mutex_unlock(&philos->args->mutex_die);
		return (1);
	}
	pthread_mutex_unlock(&philos->args->mutex_die);
	write_term(philos->id, 3, philos);
	wait_time(philos, philos->args->time_to_sleep);
	write_term(philos->id, 4, philos);
	return (0);
}
