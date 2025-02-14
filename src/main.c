/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:52:52 by serferna          #+#    #+#             */
/*   Updated: 2025/02/14 23:06:42 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_state_machine	*machine;

	machine = create_state_machine(argc, argv);
	if (machine == NULL)
		return (EXIT_FAILURE);
	machine->execute = validate_arguments_state;
	while (!machine->is_done)
		machine->execute(machine);
	printf("philo: \nTime to die: %lu\nTime to eat: %lu\nTime to sleep: %lu\nN meals: %lu\n",
		machine->global->time_to_die, machine->global->time_to_eat,
		machine->global->time_to_sleep, machine->global->n_meals);
	if (machine->error)
	{
		free(machine);
		return (EXIT_FAILURE);
	}
	free(machine);
	return (EXIT_SUCCESS);
}
