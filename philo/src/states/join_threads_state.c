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

static t_bool	all_philos_ended(t_global *global)
{
	uint64_t	i;

	i = 0;
	while (i < global->n_philos)
	{
		if (!global->philosophers[i]->is_ended)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	join_threads_state(t_state_machine *machine)
{
	t_global	*global;
	uint64_t	i;

	global = machine->global;
	i = 0;
	while (!all_philos_ended(global))
		usleep(200);
	while (i < global->n_philos)
	{
		pthread_join(global->philosophers[i]->thread, NULL);
		i++;
	}
	machine->execute = destroy_simulation_state;
}
