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

static void	unlock_forks_until_all_end(t_global *global)
{
	uint64_t	i;

	while (!all_philos_ended(global))
	{
		i = 0;
		while (i < global->n_philos)
		{
			pthread_mutex_unlock(&global->forks[i]);
			i++;
		}
	}
	while (i < global->n_philos)
	{
		pthread_mutex_unlock(&global->forks[i]);
		i++;
	}
}

void	join_threads_state(t_state_machine *machine)
{
	t_global	*global;
	uint64_t	i;

	global = machine->global;
	i = 0;
	unlock_forks_until_all_end(global);
	while (i < global->n_philos)
	{
		pthread_join(global->philosophers[i]->thread, NULL);
		i++;
	}
	machine->execute = destroy_simulation_state;
}
