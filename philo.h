/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:23 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/20 18:10:13 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_mutex_t	mtx_fork;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	int				fork_num;
	int				num;
}	t_philo;

typedef struct s_sim
{
	pthread_t		*th_philo;
	
	long		start_time;
	t_philo		*philos;
}	t_sim;

int			ft_atoi(const char *str);
void		arg_parser(char **arg, t_philo *philo, int argc);
int			number_of_philo_control(t_philo *philo, int argc);
uint64_t	get_time(void);
void    	init_threads_fork(t_sim *sim, int philo_count);
void		inits(t_sim *sim);
void		*a();

#endif