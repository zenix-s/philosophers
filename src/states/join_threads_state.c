/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads_state.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:17:24 by serferna          #+#    #+#             */
/*   Updated: 2025/02/15 12:17:24 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

//void join_threads_state(t_state_machine *machine)
//{
//	t_global *global;
//	int i;
//
//	global = machine->global;
//	i = 0;
//	while (i < global->n_philos)
//	{
//		pthread_join(global->philosophers[i]->thread, NULL);
//		i++;
//	}
//	machine->execute = monitor_simulation_state;
//}
void join_threads_state(t_state_machine *machine)
{
	t_global *global = machine->global;
	uint64_t i;

	i = 0;
	while (i < global->n_philos)
	{
		pthread_join(global->philosophers[i]->thread, NULL);
		i++;
	}
	// Transition to the cleanup state
	machine->execute = destroy_simulation_state;
}