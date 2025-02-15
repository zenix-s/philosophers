/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks_state.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:26:35 by serferna          #+#    #+#             */
/*   Updated: 2025/02/15 10:26:41 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void create_forks_state(t_state_machine *machine)
{
	t_global *global = machine->global;
	int i;

	global->forks = malloc(sizeof(pthread_mutex_t) * global->n_philos);
	if (!global->forks)
	{
		set_machine_error(machine, ERROR_MALLOC);
		return;
	}
	i = 0;
	while (i < global->n_philos)
	{
		pthread_mutex_init(&global->forks[i], NULL);
		i++;
	}
	machine->execute = create_philosophers_state;
}