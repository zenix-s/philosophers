/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers_state.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:11:01 by serferna          #+#    #+#             */
/*   Updated: 2025/02/15 10:11:07 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

static t_bool	create_philosopher(t_philosopher **philo, const int id,
		t_global *global)
{
	*philo = malloc(sizeof(t_philosopher));
	if (*philo == NULL)
		return (FALSE);
	(*philo)->id = id;
	(*philo)->meals = 0;
	(*philo)->last_meal = timestamp();
	(*philo)->global = global;
	(*philo)->l_fork = id;
	(*philo)->r_fork = (id + 1) % global->n_philos;
	(*philo)->lock_l_fork = FALSE;
	(*philo)->lock_r_fork = FALSE;
	return (TRUE);
}

void	create_philosophers_state(t_state_machine *machine)
{
	t_global	*global;
	int			i;

	global = machine->global;
	global->philosophers = malloc(sizeof(t_philosopher *) * global->n_philos);
	if (!global->philosophers)
	{
		set_machine_error(machine, ERROR_MALLOC);
		return ;
	}
	i = 0;
	while (i < global->n_philos)
	{
		if (!create_philosopher(&global->philosophers[i], i, global))
		{
			set_machine_error(machine, ERROR_MALLOC);
			return ;
		}
		i++;
	}
	machine->execute = start_simulation_state;
}
