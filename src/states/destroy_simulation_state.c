/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_simulation_state.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:59:32 by serferna          #+#    #+#             */
/*   Updated: 2025/02/15 12:59:32 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	destroy_simulation_state(t_state_machine *machine)
{
	t_global	*global;
	int			i;

	global = machine->global;
	i = 0;
	while (i < global->n_philos)
	{
		free(global->philosophers[i]);
		i++;
	}
	free(global->philosophers);
	i = 0;
	while (i < global->n_philos)
	{
		pthread_mutex_destroy(&global->forks[i]);
		i++;
	}
	free(global->forks);
	pthread_mutex_destroy(&global->write_mutex);
	free(global);
	machine->is_done = TRUE;
}
