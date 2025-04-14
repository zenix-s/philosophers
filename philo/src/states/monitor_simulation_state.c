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

static void	oh_no_the_butler_is_dead(t_global *global, uint8_t i)
{
	if (!global->dead)
	{
		global->dead = TRUE;
		printf("%lu %d died\n", timestamp() - global->start_time,
			global->philosophers[i]->id + 1);
	}
}

void	monitor_simulation_state(t_state_machine *machine)
{
	t_global	*global;
	uint8_t		i;
	t_bool		all_eaten;

	global = machine->global;
	all_eaten = TRUE;
	i = 0;
	while (i < global->n_philos)
	{
		if (is_philo_dead(global->philosophers[i]))
		{
			pthread_mutex_lock(&global->write_mutex);
			oh_no_the_butler_is_dead(global, i);
			pthread_mutex_unlock(&global->write_mutex);
			break ;
		}
		if (!has_eaten_required_meals(global->philosophers[i]))
			all_eaten = FALSE;
		i++;
	}
	if (all_eaten)
		global->dead = TRUE;
	if (global->dead)
		machine->execute = join_threads_state;
	usleep(1000);
}
