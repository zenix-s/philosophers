/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:11:54 by serferna          #+#    #+#             */
/*   Updated: 2025/02/15 12:11:54 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	*philosopher_routine(void *philosopher)
{
	t_philosopher	*philo;
	t_bool is_first_action;

	is_first_action = TRUE;
	philo = (t_philosopher *)philosopher;
	philo->last_meal = timestamp();
	philo->routine = philosopher_eat_state;
	if (is_even(philo->id))
		usleep(15000);
	while (!philo->global->dead)
	{
		if (philo->routine == philosopher_eat_state && !is_first_action)
			print_log(philosopher, THINKING);
		if (is_first_action)
			is_first_action = FALSE;
		if (has_eaten_required_meals(philosopher))
			break;
		philo->routine(philo);
	}
	return (NULL);
}
