/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_simulation_state.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:19:00 by serferna          #+#    #+#             */
/*   Updated: 2025/02/15 12:19:00 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void monitor_simulation_state(t_state_machine *machine)
{
	t_global *global;
	int i;
	t_bool all_eaten;

	global = machine->global;
	all_eaten = TRUE;
	i = 0;
	while (i < global->n_philos)
	{

		if (is_philo_dead(global->philosophers[i]))
		{
			print_log(global->philosophers[i], DIED);
			global->dead = TRUE;
			break ;
		}
		if (!has_eaten_required_meals(global->philosophers[i]))
			all_eaten = FALSE;
		i++;
	}
	if (all_eaten)
		global->dead = TRUE;
	if (global->dead)
	{
		machine->execute = destroy_simulation_state;
		return ;
	}
	usleep(1000);
}