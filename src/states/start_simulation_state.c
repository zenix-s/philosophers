/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation_state.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:14:47 by serferna          #+#    #+#             */
/*   Updated: 2025/02/15 12:14:51 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	start_simulation_state(t_state_machine *machine)
{
	t_global	*global;
	int			i;

	global = machine->global;
	i = 0;
	while (i < global->n_philos)
	{
		pthread_create(&global->philosophers[i]->thread, NULL,
			philosopher_routine, global->philosophers[i]);
		global->philosophers[i]->last_meal = timestamp();
		i++;
	}
	machine->execute = monitor_simulation_state;
}
