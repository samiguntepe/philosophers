/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <sguntepe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:16 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/13 22:35:51 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_sim	sim;
	sim.philos = malloc(sizeof(t_philo)); 
	if (argc < 5 || argc > 6)
		return (0);
	
	arg_parser(argv, sim.philos, argc);
	if (number_of_philo_control(sim.philos, argc) == 0)
		return (0);
	sim.start_time = 0;
	sim.start_time = get_time(&sim);
	printf("%ld",sim.start_time);
}
