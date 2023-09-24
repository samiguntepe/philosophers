/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:16 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/24 16:30:57 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	get_time();
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (argc < 5 || argc > 6)
		return (0);
	arg_parser(argv, philo, argc);
	if (number_of_philo_control(philo, argc) == 0)
		return (0);
	inits(philo);
}
