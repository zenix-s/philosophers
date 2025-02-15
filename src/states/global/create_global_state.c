/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_global_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:17:58 by serferna          #+#    #+#             */
/*   Updated: 2025/02/15 00:18:05 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philosophers.h"

static void	create_global(t_global **global)
{
	*global = malloc(sizeof(t_global));
	if (*global == NULL)
		return ;
	(*global)->dead = FALSE;
	(*global)->n_meals = 0;
	(*global)->die_time = 0;
	(*global)->eat_time = 0;
	(*global)->sleep_time = 0;
	(*global)->start_time = timestamp();
	(*global)->philosophers = NULL;
	(*global)->forks = NULL;
	(*global)->n_philos = 0;
}

static void	calculate_times(t_state_machine *machine)
{
	if (!to_uint8(machine->argv[1], &machine->global->n_philos))
		set_machine_error(machine, ERROR_N_PHIL);
	else if (!to_uint64(machine->argv[2], &machine->global->die_time))
		set_machine_error(machine, ERROR_DIE_TIME);
	else if (!to_uint64(machine->argv[3], &machine->global->eat_time))
		set_machine_error(machine, ERROR_EAT_TIME);
	else if (!to_uint64(machine->argv[4], &machine->global->sleep_time))
		set_machine_error(machine, ERROR_SLEEP_TIME);
	else if (machine->argc == 6 && !to_uint64(machine->argv[5],
			&machine->global->n_meals))
		set_machine_error(machine, ERROR_N_MEALS);
}

void	create_global_state(t_state_machine *machine)
{
	create_global(&machine->global);
	if (machine->global == NULL)
	{
		set_machine_error(machine, ERROR_MALLOC);
		return ;
	}
	pthread_mutex_init(&machine->global->write_mutex, NULL);
	calculate_times(machine);
	if (machine->error != NULL)
		return ;
	machine->execute = create_forks_state;
}
